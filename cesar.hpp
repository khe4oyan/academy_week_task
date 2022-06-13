#ifndef _CESAR
#define _CESAR

class Cesar{
  private:
    std::string _input_path;
    std::string _output_path;
    std::string _text;
    std::string _cesar_text;
    Side _shift_side;
    int _shift_count;
  public:
  Cesar(std::string ip, std::string op, Side sd, int shift = 3);
  void shifr();
  void unshifr();
};

// ---- class implementation

Cesar::Cesar(std::string ip, std::string op, Side sd, int shift){
  this->_input_path = ip;
  this->_output_path = op;
  this->_shift_side = sd;
  this->_shift_count = shift;

  this->_cesar_text = "";
  this->_text = "";
}

void Cesar::shifr(){
  get_text(this->_text, this->_input_path);
  this->_cesar_text = coding(this->_text, this->_shift_side, this->_shift_count);
  save_cesar_text(this->_cesar_text, this->_output_path);

  std::cout << "Shifr is done. See it in path: " << this->_output_path << std::endl;
}

void Cesar::unshifr(){
  get_text(this->_text, this->_output_path);

  if(this->_shift_side == Side::LEFT){
    this->_cesar_text = coding(this->_text, Side::RIGHT, this->_shift_count);
  }else{
    this->_cesar_text = coding(this->_text, Side::LEFT, this->_shift_count);
  }

  save_cesar_text(this->_cesar_text, this->_input_path);
  std::cout << "Unshift is done. See it in path: " << this->_input_path << std::endl;
}

#endif // _CESAR