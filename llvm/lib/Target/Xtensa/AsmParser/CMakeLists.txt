include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_component_library(LLVMXtensaAsmParser
  XtensaAsmParser.cpp

  LINK_COMPONENTS
  MC
  MCParser
  Support
  XtensaDesc
  XtensaInfo

  ADD_TO_COMPONENT
  Xtensa
  )

add_dependencies(LLVMXtensaAsmParser XtensaCommonTableGen)
