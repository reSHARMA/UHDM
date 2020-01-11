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
 * File:   port.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef PORT_H
#define PORT_H

namespace UHDM {

  class port : public ports {
  public:
    // Implicit constructor used to initialize all members,
    // comment: port();
    ~port() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    bool set_vpiParent(BaseClass* data) { vpiParent_ = data; return true;}

    unsigned int get_uhdmParentType() const { return uhdmParentType_; }

    bool set_uhdmParentType(unsigned int data) { uhdmParentType_ = data; return true;}

    std::string get_vpiFile() const { return SymbolFactory::getSymbol(vpiFile_); }

    bool set_vpiFile(std::string data) { vpiFile_ = SymbolFactory::make(data); return true; }

    unsigned int get_vpiLineNo() const { return vpiLineNo_; }

    bool set_vpiLineNo(unsigned int data) { vpiLineNo_ = data; return true;}

    VectorOfport_bit* get_bits() const { return bits_; }

    bool set_bits(VectorOfport_bit* data) { bits_ = data; return true;}

    unsigned int get_vpiType() { return vpiPort; }

    virtual unsigned int getUhdmType() { return uhdmport; }   
  private:
    
    BaseClass* vpiParent_;

    unsigned int uhdmParentType_;

    unsigned int vpiFile_;

    unsigned int vpiLineNo_;

    VectorOfport_bit* bits_;

  };

  class portFactory {
  friend Serializer;
  public:
  static port* make() {
    port* obj = new port();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<port*> objects_;
  };
 	      
  class VectorOfportFactory {
  friend Serializer;
  public:
  static std::vector<port*>* make() {
    std::vector<port*>* obj = new std::vector<port*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<port*>*> objects_;
  };

};

#endif

