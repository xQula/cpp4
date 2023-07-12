#include <fstream>
#include <utility>
#include <memory>
#include <iostream>

class Data{
private:
    std::string msg_;
protected:
    [[nodiscard]] std::string get_msg() const { return  msg_;}
public:
    explicit Data(std::string msg) : msg_(std::move(msg)){};
    virtual ~Data() = default;
    [[nodiscard]] virtual std::string print() const = 0;
};

class PrintableText: public Data{
public:
    explicit PrintableText(std::string str) : Data(std::move(str)){}
    [[nodiscard]] std::string print() const override{
        return Data::get_msg();
    }
};

class PrintableHTML: public Data{
public:
    explicit PrintableHTML(std::string str) : Data(std::move(str)){}
    [[nodiscard]] std::string print() const override{
        return "<html>" + Data::get_msg() + "<html/>";
    }
};

class PrintableJSON: public Data{
public:
    explicit PrintableJSON(std::string str) : Data(std::move(str)){}
    [[nodiscard]] std::string print() const override{
        return "{ \"data\": \"" + Data::get_msg() + "\"}";
    }
};

void saveTo(std::ostream & file,  const std::shared_ptr<Data>& ptr){
    file << ptr->print() << std::endl;
}

int main(){
    std::ofstream file("../out.txt");
    auto print = std::make_shared<PrintableJSON>("Hello");
    saveTo(file, print);
    saveTo(std::cout, print);
}