#include "options.h"

double operation(struct options options);
double trig(struct options options);

double entryPoint(FuncType ft, struct options options)
{
    double result;
    switch(ft)
    {
        case operate:
            result = operation(options);
            break;
        case trigOperations:
            result = trig(options);
            break;
    }
    return result;
}

double operation(struct options options){
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

double trig(struct options options){
    double res=0;
    std::string operate=options.operation;
    if (operate=="sin")
        res =(sin(options.num1));
    else if (operate=="cos")
        res =(cos(options.num1));
    else if ((operate=="tg")||(operate=="ctg")){
        if (cos(options.num1)==0)
            res=ERROR;
        else{
            res =(tan(options.num1));
            if (operate=="ctg"){
                if (options.num1!=0)
                    res=(1/(tan(options.num1)));
                else
                    res=ERROR;
            }
        }
    }
    return res; //98765e-99
}
