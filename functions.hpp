#ifndef _FUNCTIONS
#define _FUNCTIONS

enum Side {LEFT, RIGHT};

void get_text(std::string& text, const std::string& path = "text.txt"){
  std::ifstream file(path);

  while(!file.eof()){
    std::string tmp;
    std::getline(file, tmp);
    text += tmp;
  }
}

void save_cesar_text(std::string& text, const std::string& path = "cesar_text.txt"){
  std::ofstream file(path);

  file << text;
}

std::string left_cesaring(std::string& text, int cesar_shift){
  std::string cesar_text{};
  const int alphavit = 26;

  for(int i = 0; i < text.size(); ++i){
    if(text[i] >= 65 && text[i] <= 90){
      if(text[i] - cesar_shift < 65){
        cesar_text += text[i] + (alphavit - cesar_shift); 
      }else{
        cesar_text += text[i] - cesar_shift;
      }
    }else
    if(text[i] >= 97 && text[i] <= 122){
      if(text[i] - cesar_shift < 97){
        cesar_text += text[i] + (alphavit - cesar_shift); 
      }else{
        cesar_text += text[i] - cesar_shift;
      }
    }else{
      cesar_text += text[i];
    }
  }

  return cesar_text;
}

std::string right_cesaring(std::string& text, int cesar_shift){
  std::string cesar_text{};
  const int alphavit = 26;

  for(int i = 0; i < text.size(); ++i){
    if(text[i] >= 65 && text[i] <= 90){
      if(text[i] + cesar_shift > 90){
        cesar_text += text[i] - (alphavit - cesar_shift); 
      }else{
        cesar_text += text[i] + cesar_shift;
      }
    }else
    if(text[i] >= 97 && text[i] <= 122){
      if(text[i] + cesar_shift > 122){
        cesar_text += text[i] - (alphavit - cesar_shift); 
      }else{
        cesar_text += text[i] + cesar_shift;
      }
    }else{
      cesar_text += text[i];
    }
  }

  return cesar_text;
}

std::string coding(std::string& text, Side side = Side::RIGHT, int cesar_shift = 3){
  return side == Side::LEFT ? left_cesaring(text, cesar_shift) : 
                              right_cesaring(text, cesar_shift);
}

#endif // _FUNCTIONS