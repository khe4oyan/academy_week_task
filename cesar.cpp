#include <iostream>
#include <fstream>

#include "functions.hpp"
#include "cesar.hpp"
#include "control_block.hpp"

int main(){
  Cesar c = CB::get_info();
  CB::command(c);
}