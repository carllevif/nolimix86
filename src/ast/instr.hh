#pragma once

#include <common.hh>
#include <ast/instr-base.hh>
#include <ast/operand.hh>
#include <ast/visitor.hh>

#include <array>

namespace nolimix86
{

  namespace ast
  {

    template <opcode_t opcode, size_t operands_count>
    class instr : public instr_base
    {
      public:
        using operand_t = std::unique_ptr<operand>;
        using operands_t = std::array<operand_t, operands_count>;
        using operand_iterator = typename operands_t::iterator;
        using operand_const_iterator = typename operands_t::const_iterator;

        /// Instruction opcode
        virtual opcode_t opcode_get() const noexcept override;

        /// Operand iterators
        operand_iterator begin() noexcept;
        operand_const_iterator begin() const noexcept;
        operand_iterator end() noexcept;
        operand_const_iterator end() const noexcept;

        /// Access an operand
        constexpr operand_t& operator[](size_t) noexcept;
        constexpr const operand_t& operator[](size_t) const noexcept;

        /// Src and dst should be available only for instructions with 2
        /// operands.
        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 2, operand_t&>
        src() noexcept;

        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 2, const operand_t&>
        src() const noexcept;

        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 2, operand_t&>
        dst() noexcept;

        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 2, const operand_t&>
        dst() const noexcept;

        /// Operand should be available only for instructions with 1 operand.
        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 1, operand_t&>
        operand() noexcept;

        template <size_t count = operands_count>
        constexpr std::enable_if_t<count == 1, const operand_t&>
        operand() const noexcept;

        void accept(const_visitor&) const override;
        void accept(visitor&) override;

      protected:
        operands_t operands_;
    };

  } // namespace ast

} // namespace nolimix86

#include <ast/instr.hxx>