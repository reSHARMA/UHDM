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
 * File:   interface_tf_decl.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef INTERFACE_TF_DECL_H
#define INTERFACE_TF_DECL_H

namespace UHDM {

  class interface_tf_decl : public BaseClass {
  public:
    // Implicit constructor used to initialize all members,
    // comment: interface_tf_decl();
    ~interface_tf_decl() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    void set_vpiParent(BaseClass* data) { vpiParent_ = data; }

    unsigned int get_uhdmParentType() const { return uhdmParentType_; }

    void set_uhdmParentType(unsigned int data) { uhdmParentType_ = data; }

    std::string get_vpiFile() const { return SymbolFactory::getSymbol(vpiFile_); }

    void set_vpiFile(std::string data) { vpiFile_ = SymbolFactory::make(data); }

    unsigned int get_vpiLineNo() const { return vpiLineNo_; }

    void set_vpiLineNo(unsigned int data) { vpiLineNo_ = data; }

    unsigned int get_vpiAccessType() const { return vpiAccessType_; }

    void set_vpiAccessType(unsigned int data) { vpiAccessType_ = data; }

    VectorOftask* get_tasks() const { return tasks_; }

    void set_tasks(VectorOftask* data) { tasks_ = data; }

    VectorOffunction* get_functions() const { return functions_; }

    void set_functions(VectorOffunction* data) { functions_ = data; }

    virtual unsigned int getUhdmType() { return uhdminterface_tf_decl; }   
  private:
    
    BaseClass* vpiParent_;

    unsigned int uhdmParentType_;

    unsigned int vpiFile_;

    unsigned int vpiLineNo_;

    unsigned int vpiAccessType_;

    VectorOftask* tasks_;

    VectorOffunction* functions_;

  };

  class interface_tf_declFactory {
  friend Serializer;
  public:
  static interface_tf_decl* make() {
    interface_tf_decl* obj = new interface_tf_decl();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<interface_tf_decl*> objects_;
  };
 	      
  class VectorOfinterface_tf_declFactory {
  friend Serializer;
  public:
  static std::vector<interface_tf_decl*>* make() {
    std::vector<interface_tf_decl*>* obj = new std::vector<interface_tf_decl*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<interface_tf_decl*>*> objects_;
  };

};

#endif

