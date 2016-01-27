#include <vm/vm.hh>
#include <ast/instructions.hh>

#include <gtest/gtest.h>

namespace vm = nolimix86::vm;
namespace ast = nolimix86::ast;

TEST(vm_x86, construction)
{
  vm::x86 vm;
}

TEST(vm_x86, visit)
{
  vm::x86 vm;
  ast::mov mov;
  vm(mov);
}