/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019-2020 Alain Dargelas

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
 * File:   vpi_visitor.cpp
 * Author: alain
 *
 * Created on December 14, 2019, 10:03 PM
 */
#include <uhdm/vpi_visitor.h>

#include <string.h>

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

static bool showIDs = false;
static constexpr int kLevelIndent = 2;


#ifdef STANDARD_VPI

#include <sv_vpi_user.h>

// Missing defines from vpi_user.h, sv_vpi_user.h, They are no-op in the Standard implementation.
#define uhdmdesign 2569
#define uhdmallPackages 2570
#define uhdmallClasses 2571
#define uhdmallInterfaces 2572
#define uhdmallUdps 2573
#define uhdmallPrograms 2574
#define uhdmallModules 2575
#define uhdmtopModules 2576
#define vpiDesign 3000
#define vpiInterfaceTypespec 3001
#define vpiNets 3002
#define vpiSimpleExpr 3003
#define vpiParameters 3004
#define vpiSequenceExpr 3005
#define vpiUnsupportedStmt 4000
#define vpiUnsupportedExpr 4001
#define uhdmimport 2577

#else

#include <uhdm/sv_vpi_user.h>
#include <uhdm/vhpi_user.h>
#include <uhdm/uhdm_types.h>
#include <uhdm/containers.h>
#include <uhdm/vpi_uhdm.h>
#include <uhdm/uhdm.h>
#include <uhdm/Serializer.h>

#endif



// UHDM implementation redefine these
#ifndef vpiVarBit
  #define vpiVarBit          vpiRegBit
  #define vpiLogicVar        vpiReg
  #define vpiArrayVar        vpiRegArray
#endif


namespace UHDM {


std::string decompile(UHDM::any* handle) {
  UHDM::VisitedContainer visited;
  vpi_show_ids(true);
  if (handle == nullptr) {
    std::cout << "NULL HANDLE\n";
    return "NULL HANDLE";
  }
  vpiHandle dh = handle->GetSerializer()->MakeUhdmHandle(handle->UhdmType(), handle);
  std::stringstream out;
  visit_object(dh, 0, "decompile", &visited, out);
  std::cout << out.str() << "\n";
  vpi_release_handle(dh);
  return out.str();
}


#ifdef STANDARD_VPI

static std::string vpiTypeName(vpiHandle h) {
  int type = vpi_get(vpiType, h);
  switch (type) {
    case 35: return "vpiNamedFork";
    case 611: return "vpiShortIntVar";
    case 36: return "vpiNet";
    case 612: return "vpiIntVar";
    case 37: return "vpiNetBit";
    case 613: return "vpiShortRealVar";
    case 38: return "vpiNullStmt";
    case 614: return "vpiByteVar";
    case 40: return "vpiParamAssign";
    case 39: return "vpiOperation";
    case 615: return "vpiClassVar";
    case 41: return "vpiParameter";
    case 616: return "vpiStringVar";
    case 42: return "vpiPartSelect";
    case 617: return "vpiEnumVar";
    case 43: return "vpiPathTerm";
    case 618: return "vpiStructVar";
    case 44: return "vpiPort";
    case 619: return "vpiUnionVar";
    case 620: return "vpiBitVar";
    case 45: return "vpiPortBit";
    case 621: return "vpiClassObj";
    case 46: return "vpiPrimTerm";
    case 622: return "vpiChandleVar";
    case 47: return "vpiRealVar";
    case 623: return "vpiPackedArrayVar";
    case 624: return "vpiAlwaysType";
    case 48: return "vpiReg";
    case 49: return "vpiRegBit";
    case 50: return "vpiRelease";
    case 625: return "vpiLongIntTypespec";
    case 51: return "vpiRepeat";
    case 626: return "vpiShortRealTypespec";
    case 52: return "vpiRepeatControl";
    case 627: return "vpiByteTypespec";
    case 53: return "vpiSchedEvent";
    case 628: return "vpiShortIntTypespec";
    case 54: return "vpiSpecParam";
    case 629: return "vpiIntTypespec";
    case 630: return "vpiClassTypespec";
    case 55: return "vpiSwitch";
    case 631: return "vpiStringTypespec";
    case 56: return "vpiSysFuncCall";
    case 632: return "vpiChandleTypespec";
    case 57: return "vpiSysTaskCall";
    case 633: return "vpiEnumTypespec";
    case 58: return "vpiTableEntry";
    case 634: return "vpiEnumConst";
    case 59: return "vpiTask";
    case 60: return "vpiTaskCall";
    case 635: return "vpiIntegerTypespec";
    case 61: return "vpiTchk";
    case 636: return "vpiTimeTypespec";
    case 62: return "vpiTchkTerm";
    case 637: return "vpiRealTypespec";
    case 63: return "vpiTimeVar";
    case 638: return "vpiStructTypespec";
    case 64: return "vpiTimeQueue";
    case 639: return "vpiUnionTypespec";
    case 640: return "vpiBitTypespec";
    case 65: return "vpiUdp";
    case 641: return "vpiLogicTypespec";
    case 66: return "vpiUdpDefn";
    case 642: return "vpiArrayTypespec";
    case 67: return "vpiUserSystf";
    case 643: return "vpiVoidTypespec";
    case 68: return "vpiVarSelect";
    case 644: return "vpiTypespecMember";
    case 69: return "vpiWait";
    case 70: return "vpiWhile";
    case 645: return "vpiDistItem";
    case 646: return "vpiAliasStmt";
    case 71: return "vpiCondition";
    case 647: return "vpiThread";
    case 72: return "vpiDelay";
    case 648: return "vpiMethodFuncCall";
    case 73: return "vpiElseStmt";
    case 649: return "vpiMethodTaskCall";
    case 74: return "vpiForIncStmt";
    case 650: return "vpiClockingBlock";
    case 75: return "vpiForInitStmt";
    case 651: return "vpiClockingIODecl";
    case 76: return "vpiHighConn";
    case 652: return "vpiClassDefn";
    case 77: return "vpiLhs";
    case 653: return "vpiConstraint";
    case 78: return "vpiIndex";
    case 654: return "vpiConstraintOrdering";
    case 655: return "vpiPropertyDecl";
    case 79: return "vpiLeftRange";
    case 80: return "vpiLowConn";
    case 656: return "vpiPropertySpec";
    case 81: return "vpiParent";
    case 657: return "vpiPropertyExpr";
    case 82: return "vpiRhs";
    case 658: return "vpiMulticlockSequenceExpr";
    case 83: return "vpiRightRange";
    case 660: return "vpiPropertyInst";
    case 659: return "vpiClockedSeq";
    case 84: return "vpiScope";
    case 661: return "vpiSequenceDecl";
    case 85: return "vpiSysTfCall";
    case 662: return "vpiCaseProperty";
    case 86: return "vpiTchkDataTerm";
    case 663: return "vpiEndLine";
    case 87: return "vpiTchkNotifier";
    case 664: return "vpiSequenceInst";
    case 88: return "vpiTchkRefTerm";
    case 0: return "vpiLargeCharge";
    case 665: return "vpiImmediateAssert";
    case 1: return "vpiAlways";
    case 89: return "vpiArgument";
    case 90: return "vpiBit";
    case 666: return "vpiReturn";
    case 2: return "vpiAssignStmt";
    case 91: return "vpiDriver";
    case 667: return "vpiAnyPattern";
    case 3: return "vpiAssignment";
    case 92: return "vpiInternalScope";
    case 668: return "vpiTaggedPattern";
    case 4: return "vpiBegin";
    case 93: return "vpiLoad";
    case 670: return "vpiDoWhile";
    case 669: return "vpiStructPattern";
    case 5: return "vpiCase";
    case 94: return "vpiModDataPathIn";
    case 671: return "vpiOrderedWait";
    case 6: return "vpiCaseItem";
    case 95: return "vpiModPathIn";
    case 672: return "vpiWaitFork";
    case 7: return "vpiConstant";
    case 96: return "vpiModPathOut";
    case 673: return "vpiDisableFork";
    case 8: return "vpiContAssign";
    case 97: return "vpiOperand";
    case 674: return "vpiExpectStmt";
    case 9: return "vpiDeassign";
    case 98: return "vpiPortInst";
    case 675: return "vpiForeachStmt";
    case 99: return "vpiProcess";
    case 676: return "vpiFinal";
    case 677: return "vpiExtends";
    case 678: return "vpiDistribution";
    case 680: return "vpiEnumNet";
    case 679: return "vpiSeqFormalDecl";
    case 681: return "vpiIntegerNet";
    case 682: return "vpiTimeNet";
    case 683: return "vpiStructNet";
    case 684: return "vpiBreak";
    case 685: return "vpiContinue";
    case 686: return "vpiAssert";
    case 687: return "vpiAssume";
    case 688: return "vpiCover";
    case 700: return "vpiActual";
    case 690: return "vpiClockingEvent";
    case 689: return "vpiDisableCondition";
    case 701: return "vpiTypedefAlias";
    case 691: return "vpiReturnStmt";
    case 702: return "vpiIndexTypespec";
    case 692: return "vpiPackedArrayTypespec";
    case 703: return "vpiBaseTypespec";
    case 693: return "vpiPackedArrayNet";
    case 704: return "vpiElemTypespec";
    case 694: return "vpiImmediateAssume";
    case 695: return "vpiImmediateCover";
    case 706: return "vpiInputSkew";
    case 696: return "vpiSequenceTypespec";
    case 707: return "vpiOutputSkew";
    case 697: return "vpiPropertyTypespec";
    case 708: return "vpiGlobalClocking";
    case 698: return "vpiEventTypespec";
    case 710: return "vpiDefaultDisableIff";
    case 709: return "vpiDefaultClocking";
    case 699: return "vpiPropFormalDecl";
    case 713: return "vpiOrigin";
    case 714: return "vpiPrefix";
    case 715: return "vpiWith";
    case 718: return "vpiProperty";
    case 720: return "vpiValueRange";
    case 721: return "vpiPattern";
    case 722: return "vpiWeight";
    case 725: return "vpiTypedef";
    case 726: return "vpiImport";
    case 727: return "vpiDerivedClasses";
    case 100: return "vpiVariables";
    case 728: return "vpiVirtualInterfaceVar";
    case 730: return "vpiMethods";
    case 101: return "vpiUse";
    case 731: return "vpiSolveBefore";
    case 102: return "vpiExpr";
    case 732: return "vpiSolveAfter";
    case 103: return "vpiPrimitive";
    case 104: return "vpiStmt";
    case 734: return "vpiWaitingProcesses";
    case 105: return "vpiAttribute";
    case 735: return "vpiMessages";
    case 106: return "vpiBitSelect";
    case 736: return "vpiConstrForEach";
    case 107: return "vpiCallback";
    case 737: return "vpiLoopVars";
    case 108: return "vpiDelayTerm";
    case 738: return "vpiConstrIf";
    case 109: return "vpiDelayDevice";
    case 110: return "vpiFrame";
    case 740: return "vpiConcurrentAssertions";
    case 739: return "vpiConstrIfElse";
    case 111: return "vpiGateArray";
    case 741: return "vpiMatchItem";
    case 112: return "vpiModuleArray";
    case 742: return "vpiMember";
    case 113: return "vpiPrimitiveArray";
    case 743: return "vpiElement";
    case 114: return "vpiNetArray";
    case 744: return "vpiAssertion";
    case 115: return "vpiRange";
    case 745: return "vpiInstance";
    case 116: return "vpiRegArray";
    case 746: return "vpiConstraintItem";
    case 117: return "vpiSwitchArray";
    case 747: return "vpiConstraintExpr";
    case 118: return "vpiUdpArray";
    case 748: return "vpiElseConst";
    case 119: return "vpiActiveTimeFormat";
    case 120: return "vpiInTerm";
    case 750: return "vpiCoverageStart";
    case 749: return "vpiImplication";
    case 121: return "vpiInstanceArray";
    case 751: return "vpiCoverageStOp";
    case 122: return "vpiLocalDriver";
    case 752: return "vpiCoverageReset";
    case 123: return "vpiLocalLoad";
    case 753: return "vpiCoverageCheck";
    case 124: return "vpiOutTerm";
    case 754: return "vpiCoverageMerge";
    case 125: return "vpiPorts";
    case 755: return "vpiCoverageSave";
    case 126: return "vpiSimNet";
    case 127: return "vpiTaskFunc";
    case 128: return "vpiContAssignBit";
    case 758: return "vpiFsm";
    case 129: return "vpiNamedEventArray";
    case 130: return "vpiIndexedPartSelect";
    case 759: return "vpiFsmHandle";
    case 760: return "vpiAssertCoverage";
    case 131: return "vpiBaseExpr";
    case 761: return "vpiFsmStateCoverage";
    case 132: return "vpiWidthExpr";
    case 762: return "vpiStatementCoverage";
    case 133: return "vpiGenScopeArray";
    case 763: return "vpiToggleCoverage";
    case 134: return "vpiGenScope";
    case 135: return "vpiGenVar";
    case 765: return "vpiCovered";
    case 136: return "vpiAutomatics";
    case 766: return "vpiCoverMax";
    case 767: return "vpiCoveredCount";
    case 770: return "vpiAssertAttemptCovered";
    case 771: return "vpiAssertSuccessCovered";
    case 772: return "vpiAssertFailureCovered";
    case 773: return "vpiAssertVacuousSuccessCovered";
    case 774: return "vpiAssertDisableCovered";
    case 775: return "vpiFsmStates";
    case 776: return "vpiFsmStateExpression";
    case 777: return "vpiAssertKillCovered";
    case 10: return "vpiDefParam";
    case 901: return "vpiRestrict";
    case 11: return "vpiDelayControl";
    case 902: return "vpiClockedProp";
    case 12: return "vpiDisable";
    case 903: return "vpiLetDecl";
    case 13: return "vpiEventControl";
    case 904: return "vpiLetExpr";
    case 14: return "vpiEventStmt";
    case 905: return "vpiCasePropertyItem";
    case 15: return "vpiFor";
    case 16: return "vpiForce";
    case 17: return "vpiForever";
    case 18: return "vpiFork";
    case 20: return "vpiFunction";
    case 19: return "vpiFuncCall";
    case 21: return "vpiGate";
    case 22: return "vpiIf";
    case 23: return "vpiIfElse";
    case 24: return "vpiInitial";
    case 600: return "vpiPackage";
    case 25: return "vpiIntegerVar";
    case 601: return "vpiInterface";
    case 26: return "vpiInterModPath";
    case 602: return "vpiProgram";
    case 27: return "vpiIterator";
    case 603: return "vpiInterfaceArray";
    case 28: return "vpiIODecl";
    case 604: return "vpiProgramArray";
    case 30: return "vpiMemoryWord";
    case 29: return "vpiMemory";
    case 605: return "vpiTypespec";
    case 31: return "vpiModPath";
    case 606: return "vpiModport";
    case 32: return "vpiModule";
    case 607: return "vpiInterfaceTfDecl";
    case 33: return "vpiNamedBegin";
    case 608: return "vpiRefObj";
    case 34: return "vpiNamedEvent";
    case 609: return "vpiTypeParameter";
    case 610: return "vpiLongIntVar";
  }
}

#endif

static void release_handle(vpiHandle obj_h) {
#ifndef STANDARD_VPI
  vpi_release_handle(obj_h);
#endif
}

static std::string visit_value(s_vpi_value* value) {
  if (value == nullptr)
    return "";
  switch (value->format) {
  case vpiIntVal:
      return std::string("|INT:")
          .append(std::to_string(value->value.integer))
          .append("\n");
  case vpiUIntVal:
    return std::string("|UINT:")
        .append(std::to_string(value->value.uint))
        .append("\n");
  case vpiStringVal:
    return std::string("|STRING:")
        .append((const char*)value->value.str)
        .append("\n");
  case vpiBinStrVal:
    return std::string("|BIN:")
        .append((const char*)value->value.str)
        .append("\n");
  case vpiHexStrVal:
    return std::string("|HEX:")
        .append((const char*)value->value.str)
        .append("\n");
  case vpiOctStrVal:
    return std::string("|OCT:")
        .append((const char*)value->value.str)
        .append("\n");
  case vpiRealVal:
    return std::string("|REAL:")
        .append(std::to_string(value->value.real))
        .append("\n");
  case vpiScalarVal:
    return std::string("|SCAL:")
        .append(std::to_string(value->value.scalar))
        .append("\n");
  case vpiDecStrVal:
    return std::string("|DEC:")
        .append((const char*)value->value.str)
        .append("\n");
  }
  return "";
}

static std::string visit_delays(s_vpi_delay* delay) {
  if (delay == nullptr)
    return "";
  switch (delay->time_type) {
  case vpiScaledRealTime:
    return std::string("|#").append(std::to_string(delay->da[0].low)).append("\n");
  }
  return "";
}

static std::ostream &stream_indent(std::ostream &out, int indent) {
  out << std::string(indent, ' ');
  return out;
}

<PRIVATE_OBJECT_VISITORS>
void visit_object(vpiHandle obj_h, int indent, const char *relation, VisitedContainer* visited, std::ostream& out, bool shallowVisit) {
  if (!obj_h)
    return;
#ifdef STANDARD_VPI

  const bool alreadyVisited = visited->find(obj_h) != visited->end();
  visited->insert(obj_h);

#else

  const uhdm_handle* const handle = (const uhdm_handle*) obj_h;
  const BaseClass* const object = (const BaseClass*) handle->object;
  const bool alreadyVisited = (visited->find(object) != visited->end());
  if (!shallowVisit)
    visited->insert(object);

#endif

  const unsigned int objectType = vpi_get(vpiType, obj_h);

  {
    std::string hspaces;
    std::string rspaces;
    if (indent >= kLevelIndent) {
      hspaces = std::string(indent - 2, ' ');
      rspaces.assign(hspaces).append("|");
      hspaces.append("\\_");
    }

    if (strlen(relation) != 0) {
      out << rspaces << relation << ":\n";
    }

#ifdef STANDARD_VPI

    out << hspaces << vpiTypeName(obj_h) << "(" << vpi_get(vpiType, obj_h) << "): ";

#else

    out << hspaces << UHDM::VpiTypeName(obj_h) << ": ";

#endif

    bool needs_separator = false;
    if (const char* s = vpi_get_str(vpiDefName, obj_h)) {  // defName
      out << s;
      needs_separator = true;
    }
    if (const char* s = vpi_get_str(vpiFullName, obj_h)) {   // objectName
      if (needs_separator) out << " ";
      out << "(" << s << ")";  // objectName
    } else if (const char* s = vpi_get_str(vpiName, obj_h)) {   // objectName
      if (needs_separator) out << " ";
      out << "(" << s << ")";  // objectName
    }

#ifndef STANDARD_VPI

    if (showIDs)
      out << ", id:" << object->UhdmId();

#endif

    if (objectType == vpiModule || objectType == vpiProgram || objectType == vpiClassDefn || objectType == vpiPackage ||
        objectType == vpiInterface || objectType == vpiUdp) {
      if (const char* s = vpi_get_str(vpiFile, obj_h)) {
        if (int l = vpi_get(vpiLineNo, obj_h)) {
          out << " " << s << ":" << l;  // fileName, line
          if (int c = vpi_get(vpiColumnNo, obj_h)) {
            out << ":" << c << ": ";  // , column
          } else {
            out << ": ";
          }
          if (int c = vpi_get(vpiEndLineNo, obj_h)) {
            out << ", endln:" << c << ":" << vpi_get(vpiEndColumnNo, obj_h);  // , endline, endCol
          }
        } else {
           out << ", file:" << s;  // fileName
        }
      }
    } else {
      if (int l = vpi_get(vpiLineNo, obj_h)) {
        if (int c = vpi_get(vpiColumnNo, obj_h)) {
          out << ", line:" << l << ":" << c;
        } else {
          out << ", line:" << l;
        }
        if (int c = vpi_get(vpiEndLineNo, obj_h)) {
          out << ", endln:" << c << ":" << vpi_get(vpiEndColumnNo, obj_h);  // , endline, endCol
        }
      }
    }
    if (vpiHandle par = vpi_handle(vpiParent, obj_h)) {
      if (const char* parentName = vpi_get_str(vpiFullName, par)) {
        out << ", parent:" << parentName;
      } else if (const char* parentName = vpi_get_str(vpiName, par)) {
        out << ", parent:" << parentName;
      }
      if (showIDs) {
        const uhdm_handle* const phandle = (const uhdm_handle*) par;
        const BaseClass* const pobject = (const BaseClass*) phandle->object;
        out << ", parID:" << pobject->UhdmId();
      }
      vpi_free_object(par);
    }
    out << "\n";
  }

  if (alreadyVisited || shallowVisit) {
    return;
  }
<OBJECT_VISITORS>
}

// Public interface
void visit_designs (const std::vector<vpiHandle>& designs, std::ostream &out) {
  for (auto design : designs) {
    VisitedContainer visited;
    visit_object(design, 0, "", &visited, out);
  }
}

std::string visit_designs (const std::vector<vpiHandle>& designs) {
  std::stringstream out;
  visit_designs(designs, out);
  return out.str();
}

};

void vpi_show_ids(bool show) {
  showIDs = show;
}

extern "C" {
  void vpi_decompiler (vpiHandle design) {
    std::vector<vpiHandle> designs;
    designs.push_back(design);
    UHDM::visit_designs(designs, std::cout);
    std::cout << std::endl;
  }
}
