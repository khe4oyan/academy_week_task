#ifndef _CONTROL_BLOCK
#define _CONTROL_BLOCK

namespace CB{ // control block
  Cesar get_info(){
    std::string path{};
    std::string out_path{};
    std::string side{};
    int shift_count{};

    std::cout << "Enter path name: ";
    std::cin >> path;

    std::cout << "Enter output path name: ";
    std::cin >> out_path;

    std::cout << "Enter side( l / r ): ";
    std::cin >> side;
    Side shift_side;

    if(side == "l"){
      shift_side = Side::LEFT;
    }else 
    if(side == "r"){
      shift_side = Side::RIGHT;
    }else{
      std::cout << "Undefined side\n";
      exit(0);
    }

    std::cout << "Enter shift count: ";
    std::cin >> shift_count;

    Cesar c(path, out_path, shift_side, shift_count);
    return c;
  }

  void command(Cesar& c){
    bool work = true;
    while(work){
      std::string comm;
      std::cout << "\n========\n";
      std::cout << "Enter what you want to do ( shifr / unshift / exit )\n>>";
      std::cin >> comm;

      if(comm == "shifr"){
        c.shifr();
        continue;
      }
      if(comm == "unshifr"){
        c.unshifr();
        continue;
      }
      if(comm == "exit"){
        std::cout << "Programm ended\n";
        exit(0);
      }
    }
  }
} 

#endif // _CONTROL_BLOCK