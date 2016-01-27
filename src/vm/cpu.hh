#pragma once

#include <ast/operand.hh>
#include <x86/registers.hh>

#include <vector>
#include <unordered_map>

namespace nolimix86
{

  namespace cpu
  {

    struct x86
    {
      using word_t = uint32_t;
      using reg_t = ::nolimix86::x86::reg;

      /// Get the value of an operand.
      word_t value_of(const ast::operand&);

      /// Set the value of a register/memory.
      void set_value(const ast::operand&, word_t);

      /// Actions on the stack.
      void push(const ast::operand&);
      void pop(const ast::operand&);

      std::unordered_map<reg_t, word_t> regs_;
      std::vector<word_t> stack_;
    };

  } // namespace vm

} // namespace nolimix86