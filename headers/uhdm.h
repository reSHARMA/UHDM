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
 * File:   <CLASSNAME>.h
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#include <string>
#include <vector>
#ifndef UHDM_H
#define UHDM_H
#include "include/sv_vpi_user.h"
#include "include/vhpi_user.h"
#include "include/vpi_uhdm.h"
#include "headers/containers.h"

#define uhdmprocess 2078
#define uhdmscope 2079
#define uhdmbegin 2080
#define uhdmnamed_begin 2081
#define uhdmexpr_dist 2082
#define uhdmexpr 2083
#define uhdmdistribution 2084
#define uhdmoperand_group 2085
#define uhdmoperation 2086
#define uhdmoperands 2087
#define uhdmref_obj 2088
#define uhdmvariables 2089
#define uhdmtask_func 2090
#define uhdmleft_expr 2091
#define uhdmright_expr 2092
#define uhdmvariables 2089
#define uhdmclass_defn 2093
#define uhdmref_obj 2088
#define uhdmio_decl 2094
#define uhdmtask 2095
#define uhdmfunction 2096
#define uhdmmodport 2097
#define uhdmio_decls 2098
#define uhdminterface 2099
#define uhdminterface_tf_decl 2100
#define uhdmtasks 2101
#define uhdmfunctions 2102
#define uhdmcont_assign 2103
#define uhdmport 2104
#define uhdmprimitive 2105
#define uhdmmod_path 2106
#define uhdmtchk 2107
#define uhdmdef_param 2108
#define uhdmio_decl 2094
#define uhdmalias_stmt 2109
#define uhdmclocking_block 2110
#define uhdmrange 2111
#define uhdmparam_assign 2112
#define uhdminstance_array 2113
#define uhdmexpr 2083
#define uhdmleft_expr 2091
#define uhdmright_expr 2092
#define uhdminstances 2114
#define uhdmrange 2111
#define uhdmmodules 2115
#define uhdminterface_array 2116
#define uhdmparam_assigns 2117
#define uhdmprogram_array 2118
#define uhdmmodule_array 2119
#define uhdmparam_assigns 2117
#define uhdmprimitive_array 2120
#define uhdmdelay 2121
#define uhdmprimitives 2122
#define uhdmgate_array 2123
#define uhdmswitch_array 2124
#define uhdmudp_array 2125
#define uhdmnet 2126
#define uhdmarray_net 2127
#define uhdmlogic_var 2128
#define uhdmarray_var 2129
#define uhdmnamed_event 2130
#define uhdmnamed_event_array 2131
#define uhdmparameters 2132
#define uhdmspec_param 2133
#define uhdmassertion 2134
#define uhdmtypespec 2135
#define uhdmclass_defn 2093
#define uhdminstance 2136
#define uhdmtask_func 2090
#define uhdmnet 2126
#define uhdmarray_net 2127
#define uhdmvariables 2089
#define uhdmparameters 2132
#define uhdmassertion 2134
#define uhdmtypespec 2135
#define uhdmclass_defn 2093
#define uhdminstance 2136
#define uhdmprograms 2137
#define uhdmprogram_arrays 2138
#define uhdmlogic_var 2128
#define uhdmarray_var 2129
#define uhdmarray_var_mem 2139
#define uhdmnamed_event 2130
#define uhdmnamed_event_array 2131
#define uhdmspec_param 2133
#define uhdmmodule 2140
#define uhdminterface 2099
#define uhdmexpr_dist 2082
#define uhdminstance_array 2113
#define uhdmprocess 2078
#define uhdminterface_tf_decls 2141
#define uhdmmodports 2142
#define uhdmglobal_clocking 2143
#define uhdmdefault_clocking 2144
#define uhdmmod_paths 2145
#define uhdmcont_assigns 2146
#define uhdminterfaces 2147
#define uhdminterface_arrays 2148
#define uhdmprogram 2149
#define uhdminstance_array 2113
#define uhdmexpr_dist 2082
#define uhdmprocess 2078
#define uhdmdefault_clocking 2144
#define uhdminterfaces 2147
#define uhdminterface_arrays 2148
#define uhdmcont_assigns 2146
#define uhdmclocking_blocks 2150
#define uhdmpackage 2151
#define uhdmmodule 2140
#define uhdmexpr_dist 2082
#define uhdminstance_array 2113
#define uhdmscope 2079
#define uhdmprocess 2078
#define uhdmprimitives 2122
#define uhdmprimitive_arrays 2152
#define uhdmglobal_clocking 2143
#define uhdmdefault_clocking 2144
#define uhdmmodule_array 2119
#define uhdmports 2153
#define uhdminterfaces 2147
#define uhdminterface_arrays 2148
#define uhdmcont_assigns 2146
#define uhdmmodules 2115
#define uhdmmodule_arrays 2154
#define uhdmmod_paths 2145
#define uhdmtchks 2155
#define uhdmdef_params 2156
#define uhdmio_decls 2098
#define uhdmalias_stmts 2157
#define uhdmclocking_blocks 2150
#define uhdmdesign 2158
#define uhdmallModules 2159
#define uhdmtopModules 2160
#define uhdmallPrograms 2161
#define uhdmallPackages 2162


#include "headers/process.h"
#include "headers/scope.h"
#include "headers/begin.h"
#include "headers/named_begin.h"
#include "headers/expr_dist.h"
#include "headers/expr.h"
#include "headers/distribution.h"
#include "headers/operand_group.h"
#include "headers/operation.h"
#include "headers/ref_obj.h"
#include "headers/variables.h"
#include "headers/task_func.h"
#include "headers/task.h"
#include "headers/function.h"
#include "headers/modport.h"
#include "headers/interface_tf_decl.h"
#include "headers/cont_assign.h"
#include "headers/port.h"
#include "headers/primitive.h"
#include "headers/mod_path.h"
#include "headers/tchk.h"
#include "headers/def_param.h"
#include "headers/io_decl.h"
#include "headers/alias_stmt.h"
#include "headers/clocking_block.h"
#include "headers/range.h"
#include "headers/param_assign.h"
#include "headers/instance_array.h"
#include "headers/interface_array.h"
#include "headers/program_array.h"
#include "headers/module_array.h"
#include "headers/primitive_array.h"
#include "headers/gate_array.h"
#include "headers/switch_array.h"
#include "headers/udp_array.h"
#include "headers/net.h"
#include "headers/array_net.h"
#include "headers/logic_var.h"
#include "headers/array_var.h"
#include "headers/named_event.h"
#include "headers/named_event_array.h"
#include "headers/parameters.h"
#include "headers/spec_param.h"
#include "headers/assertion.h"
#include "headers/typespec.h"
#include "headers/class_defn.h"
#include "headers/instance.h"
#include "headers/interface.h"
#include "headers/program.h"
#include "headers/package.h"
#include "headers/module.h"
#include "headers/design.h"


#endif

