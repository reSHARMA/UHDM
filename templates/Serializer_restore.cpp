/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   Serializer_restore.cpp
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */
#include <uhdm/Serializer.h>

#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

#if defined(_MSC_VER)
  #include <io.h>
  #pragma warning(push)
  #pragma warning(disable : 4244)  // 'argument' : conversion from 'type1' to 'type2', possible loss of data
#else
  #include <unistd.h>
  #if !(defined(__MINGW32__) || defined(__CYGWIN__))
    #define O_BINARY 0
  #endif
#endif

#include <iostream>
#include <map>
#include <vector>

#include <capnp/message.h>
#include <capnp/serialize-packed.h>

#include "UHDM.capnp.h"
#include <uhdm/uhdm.h>


namespace UHDM {
template <typename T>
inline T* Serializer::Make(FactoryT<T>* const factory) {
  T* const obj = factory->Make();
  obj->SetSerializer(this);
  obj->UhdmId(objId_++);
  return obj;
}

template <typename T>
inline std::vector<T*>* Serializer::Make(FactoryT<std::vector<T*>>* const factory) {
  return factory->Make();
}

<FACTORY_FUNCTION_IMPLEMENTATIONS>

template<typename T, typename>
inline void Serializer::SetRestoreId_(FactoryT<T>* const factory, unsigned long count) {
  for (unsigned int i = 0; i < count; ++i) {
    SetId(Make<T>(factory), i);
  }
}

struct Serializer::RestoreAdapter {
  void operator()(Any::Reader reader, Serializer *const serializer, BaseClass *const obj) const {
    obj->UhdmParentType(reader.getUhdmParentType());
    obj->VpiParent(serializer->GetObject(reader.getUhdmParentType(), reader.getVpiParent() - 1));
    obj->VpiFile(std::filesystem::path(serializer->symbolMaker.GetSymbol(reader.getVpiFile())));
    obj->VpiLineNo(reader.getVpiLineNo());
    obj->VpiColumnNo(reader.getVpiColumnNo());
    obj->VpiEndLineNo(reader.getVpiEndLineNo());
    obj->VpiEndColumnNo(reader.getVpiEndColumnNo());
    obj->UhdmId(reader.getUhdmId());
  };

<CAPNP_RESTORE_ADAPTERS>

  template<typename T, typename U, typename = typename std::enable_if<std::is_base_of<BaseClass, T>::value>::type>
  void operator()(typename ::capnp::List<U>::Reader reader, Serializer *serializer, std::vector<T*> &objects) const {
    unsigned long index = 0;
    for (typename U::Reader obj : reader)
      operator()(obj, serializer, objects[index++]);
  }
};

const std::vector<vpiHandle> Serializer::Restore(const std::string& file) {
  Purge();
  std::vector<vpiHandle> designs;
  int fileid = open(file.c_str(), O_RDONLY | O_BINARY);
  ::capnp::ReaderOptions options;
  options.traversalLimitInWords = ULLONG_MAX;
  options.nestingLimit = 1024;
  ::capnp::PackedFdMessageReader message(fileid, options);
  UhdmRoot::Reader cap_root = message.getRoot<UhdmRoot>();

  ::capnp::List<::capnp::Text>::Reader symbols = cap_root.getSymbols();
  for (auto symbol : symbols) {
    symbolMaker.Make(symbol);
  }

<CAPNP_INIT_FACTORIES>

  RestoreAdapter adapter;
<CAPNP_RESTORE_FACTORIES>

   for (auto d : designMaker.objects_) {
    vpiHandle designH = uhdm_handleMaker.Make(uhdmdesign, d);
    designs.push_back(designH);
  }

  close(fileid);
  return designs;
}

#if (defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__))
  #pragma warning(pop)
#endif
}  // namespace UHDM
