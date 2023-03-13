#include "options.h"

double operate(struct options options){
    double res=0;
    std::string operate=options.operation;
    if (operate=="+")
        res=options.num1+options.num2;
    else if (operate=="-")
        res=options.num1-options.num2;
    else if (operate=="*")
        res=options.num1*options.num2;
    else if ((operate=="/")&&(options.num2!=0))
        res=options.num1/options.num2;
    else if ((operate=="/")&&(options.num2==0))
        res=ERROR;
    return res; //98765e-99
}

double trigOperations(struct options options){
    double res=0;
    std::string operate=options.operation;
    if (operate=="sin")
        res =(sin(options.num1));
    else if (operate=="cos")
        res =(cos(options.num1));
    else if ((operate=="tg")||(operate=="ctg")){
        res =(tan(options.num1));
        if (operate=="ctg"){
            if (options.num1!=0)
                res=(1/(tan(options.num1)));
            else
                res=ERROR;
        }
    }
    return res; //98765e-99
}
