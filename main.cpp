#include <iostream>
#include "Customer.h"
#include "Customers.h"
#include "Contact.h"
#include "Charge.h"
#include <list>

int main() {
    Contact jon("Jon","120 Little Alum Rd","jon.rubio.92@gmail.com");
    Contact keith("Keith","29 Phoebe Dr","kgeneva@qmail.qcc.edu");
    Contact bishoy("Bishoy","Middle of Nowhere, Douglas, Ma", "bishoysolimon@qmail.qcc.edu");
    Contact nick("Nikolaos","Worcester, Ma","nkonstinaou@qmail.qcc.edu");
    Contact loi("Hao","Worcester, Ma","haoloi@qcc.edu");

    Charge walmart("Walmart",200.00);
    Charge target("Target",5.00);
    Charge homedepot("Home Depot",125.00);
    Charge lowes("Lowes",25.00);
    Charge stopandshop("Stop & Shop",150);
    Charge marshalls("Marshalls", 63.00);
    Charge tmobile("TMobile",313.00);

    list<Charge> joncharges;
    joncharges.push_back(tmobile);
    joncharges.push_back(homedepot);
    joncharges.push_back(lowes);
    joncharges.push_back(marshalls);

    list<Charge> keithcharges;
    keithcharges.push_back(stopandshop);
    keithcharges.push_back(walmart);
    keithcharges.push_back(tmobile);

    list<Charge> bishoycharges;
    bishoycharges.push_back(tmobile);
    bishoycharges.push_back(target);
    bishoycharges.push_back(target);
    bishoycharges.push_back(walmart);

    list<Charge> nickcharges;
    nickcharges.push_back(walmart);
    nickcharges.push_back(walmart);
    nickcharges.push_back(walmart);

    list<Charge> loicharges;
    loicharges.push_back(marshalls);
    loicharges.push_back(target);
    loicharges.push_back(tmobile);
    loicharges.push_back(homedepot);

    Customer jonr("1234",jon,5000.00,joncharges);
    Customer keithg("3412",keith,2500.00,keithcharges);
    Customer bishoys("2344", bishoy,3200.00,bishoycharges);
    Customer nickk("8874",nick,2200.00,nickcharges);
    Customer hloi("9999",loi,10000.00,loicharges);

    Customers<Customer> mycustomers;
    mycustomers.insert(jonr);
    mycustomers.insert(keithg);
    mycustomers.insert(bishoys);
    mycustomers.insert(nickk);
    mycustomers.insert(hloi);
    std::cout << mycustomers.to_string();
    int x = mycustomers.count_big_limits(9000.00);
    std::cout << x << "\n";

    std::cout << std::boolalpha << mycustomers.any_over_limit();

    mycustomers.increase_limit("1234",7000.00);
//    const Customer *jonr2 = mycustomers.find("1234");
//    const Customer *jon3 = mycustomers.find("1234");
    std::cout<< mycustomers.to_string();

    return 0;
}
