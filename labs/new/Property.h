
class Property {

protected:

    double worth;

public:

    Property(double x) {

        worth = x;
    }
    
    double tax_calculation();
    double income_tax_calculation();


};