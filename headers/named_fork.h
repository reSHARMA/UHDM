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
 * File:   named_fork.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#ifndef NAMED_FORK_H
#define NAMED_FORK_H

namespace UHDM {

  class named_fork : public scope {
  public:
    // Implicit constructor used to initialize all members,
    // comment: named_fork();
    ~named_fork() final {}
    
    BaseClass* get_vpiParent() const { return vpiParent_; }

    void set_vpiParent(BaseClass* data) { vpiParent_ = data; }

    unsigned int get_uhdmParentType() const { return uhdmParentType_; }

    void set_uhdmParentType(unsigned int data) { uhdmParentType_ = data; }

    std::string get_vpiFile() const { return SymbolFactory::getSymbol(vpiFile_); }

    void set_vpiFile(std::string data) { vpiFile_ = SymbolFactory::make(data); }

    unsigned int get_vpiLineNo() const { return vpiLineNo_; }

    void set_vpiLineNo(unsigned int data) { vpiLineNo_ = data; }

    int get_vpiJoinType() const { return vpiJoinType_; }

    void set_vpiJoinType(int data) { vpiJoinType_ = data; }

    virtual unsigned int getUhdmType() { return uhdmnamed_fork; }   
  private:
    
    BaseClass* vpiParent_;

    unsigned int uhdmParentType_;

    unsigned int vpiFile_;

    unsigned int vpiLineNo_;

    int vpiJoinType_;

  };

  class named_forkFactory {
  friend Serializer;
  public:
  static named_fork* make() {
    named_fork* obj = new named_fork();
    objects_.push_back(obj);
    return obj;
  }
  private:
    static std::vector<named_fork*> objects_;
  };
 	      
  class VectorOfnamed_forkFactory {
  friend Serializer;
  public:
  static std::vector<named_fork*>* make() {
    std::vector<named_fork*>* obj = new std::vector<named_fork*>();
    objects_.push_back(obj);
    return obj;
  }
  private:
  static std::vector<std::vector<named_fork*>*> objects_;
  };

};

#endif

