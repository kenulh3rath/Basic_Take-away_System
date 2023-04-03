#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <regex>
#include <fstream>


using namespace std;

int MANAGERCOUNT = 0;
int CHEFCOUNT = 0;
int RECEPTIONISTCOUNT = 0;
int DELIVERYDRIVERCOUNT = 0;
int STAFFCOUNT = 0;
int CUSTOMERCOUNT = 0;
int MENUITEMS = 0;
int ORDERCOUNT = 0;
int DELIVERYORDERCOUNT = 0;
int COLLECTIONORDERCOUNT = 0;

float REPORT_TOTAL = 0;

vector<string> POSTCODES;  // Stores valid postcodes




/** ------------------------- Classes start ------------------------- **/

/** Base/ Parent Class **/
class CompanyStaff
{
protected:
    int StaffID;
    string FirstName, EmergencyContactName;
    string LastName;
    int HouseNo;
    string HouseRd;
    string HouseLocatedCity;
    string Postcode;
    long long PhoneNumber, EmergencyContactPhoneNumber;
    string Email;
    string Gender;

public:
    CompanyStaff(){
        StaffID = 0;
        FirstName = "";
        LastName = "";
        HouseNo = 0;
        HouseRd = "";
        HouseLocatedCity = "";
        Postcode = "";
        PhoneNumber = 0;
        Email = "";
        Gender = "";
        EmergencyContactName = "";
        EmergencyContactPhoneNumber = 0;
    }
    // Setters
    void setStaffId(int);
    void setName(string, string);
    void setAddress(int, string, string, string);
    void setPhoneNumber(long long);
    void setEmail(string);
    void setGender(string);
    void setEmergencyContact(long long, string);

    // Getters
    [[nodiscard]] int getID() const;
    string getName();
    string getAddress();
    [[nodiscard]] long long getPhoneNumber() const;
    string getEmail();
    string getGender();
    void getEmergency();

};

/** Derived/ Child Class **/
class Chef : public CompanyStaff
{
private:
    string CuisineSpeciality;
    string Cuisines[2] = {"South Asian", "Chinese"};

public:
    Chef() : CuisineSpeciality(" "){};

    void setCuisine();
    void inputCuisine(string);
}tempChef;

/** Derived/ Child Class **/
class Manager : public CompanyStaff
{
}tempManager;

/** Derived/ Child Class **/
class Receptionist : public CompanyStaff
{
}tempReceptionist;

/** Derived Child Class **/
class DeliveryDriver : public CompanyStaff
{
private:
    string VehicleRegistrationNo;
    string DrivingLicenceNo;

public:
    DeliveryDriver(){
        VehicleRegistrationNo = "";
        DrivingLicenceNo = "";
    }

    void setVehicleRegistrationNo();

    void setDrivingLicenceNo();

    void inputVehicleRegNo(string);

    void inputLicenceNo(string);
}tempDeliveryDriver;

/** Class **/
class Customer
{
private:
    int CustomerID;
    string Name;
    long long phoneNumber;
    string Address;
    int orders;

public:
    Customer(){
        CustomerID = 0;
        Name = "Not Given";
        phoneNumber = 0;
        Address = "Not Given";
        orders = 0;
    }

    void setID(int);
    void setName(string, string);
    void setname(string);
    void setPhoneNumber(long long);
    void setAddress(string);
    void setOrders(int);
    void setOrder();

    [[nodiscard]] int getID() const;
    string getName();
    [[nodiscard]] long long getPhoneNumber() const;
    string getAddress();
    [[nodiscard]] int getOrder() const;
}tempCustomer;

/** Class **/
class Menu
{
private:
    int ItemCode;
    string ItemName;
    string ItemDescription;
    string CuisineType;
    bool Availabilty;
    float Price;

public:
    Menu(){
        ItemName = "";
        ItemDescription = "";
        CuisineType = "";
        Availabilty = true;
        ItemCode = 0;
        Price = 0;
    }

    void setItemCode(int);
    void setItemName(string);
    void setItemDescription(string);
    void setCuisineType(string);
    void setItemPrice(float);
    void setAvailability(bool);

    [[nodiscard]] int getItemCode() const;
    string getItemName();
    string getItemDescription();
    string getCuisineType();
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] string getAvailability() const;
}tempMenu;

/** Base/ Parent Class **/
class OrderDetails{
protected:
    int OrderID;
    vector<string> ItemNames;
    vector<float> ItemPrice;
    float OrderTotal;

public:
    OrderDetails(){
        OrderID = 0;
        OrderTotal = 0;
    }
    void setOrderID(int);
    void setItemName(string);
    void setItemPrice(float);
    void setItemtotal(float);
    void clearItems();

    [[nodiscard]] int getOrderID() const;
    void getItemNames(vector<string>&);
    void getItemPrices(vector<float>&);
    [[nodiscard]] float getTotal() const;
}tempOrder;

/** Derived Child Class **/
class DeliveryOrder : public OrderDetails{
private:
    int DriverID;

public:
    DeliveryOrder(){
        DriverID = 0;
    }

    void setDriverID(int);

    int getDriverID();
}tempDeliveryOrder;

/**------------------------------ Setters ------------------------------**/

/** Stores ID **/
void CompanyStaff::setStaffId(int id_){
    StaffID = id_;
}

/** Stores Name **/
void CompanyStaff::setName(string lastName_, string firstName_){
    FirstName = firstName_;
    LastName = lastName_;
}

/** Stores Address **/
void CompanyStaff::setAddress(int no_, string road_, string city_, string postcode_){
    HouseNo = no_;
    HouseRd = road_;
    HouseLocatedCity = city_;
    Postcode = postcode_;
}

/** Stores Phone Number **/
void CompanyStaff::setPhoneNumber(long long phoneNum_){
    PhoneNumber = phoneNum_;
}

void CompanyStaff::setEmail(string email_){
    Email = email_;
}

/** Stores Gender **/
void CompanyStaff::setGender(string gen_){
    Gender = gen_;
}

/** Stores Emergency Contact Details **/
void CompanyStaff::setEmergencyContact(long long phoneNum_, string name_){
    EmergencyContactName = name_;
    EmergencyContactPhoneNumber = phoneNum_;
}


void Chef::setCuisine(){
    int input_;
    cout << "Cuisine Speciality" << endl;
    for (int i = 0; i < 2; i++) {
        cout << i + 1 << " - " << Cuisines[i] << endl;
    }
    cin >> input_;

    if (input_ == 1){CuisineSpeciality = Cuisines[0];}
    else{CuisineSpeciality = Cuisines[1];}
}


void DeliveryDriver::setVehicleRegistrationNo(){
    cout << "Vehicle Registration No :";
    cin >> VehicleRegistrationNo;
}

void DeliveryDriver::setDrivingLicenceNo(){
    cout << "Driving Licence No :";
    cin >> DrivingLicenceNo;
}


/** Stores customer ID **/
void Customer::setID(int id_){
    CustomerID = id_;
}

/** Stores customer Name **/
void Customer::setName(string fName_, string lName_){
    Name = fName_ + " " + lName_;
}

void Customer::setname(string name_){
    Name = name_;
}

/** Stores customer phone number **/
void Customer::setPhoneNumber(long long phoneNum_){
    phoneNumber = phoneNum_;
}

/** Stores customer Address **/
void Customer::setAddress(string address_){
    Address = address_;
}

void Customer::setOrders(int orders_) {
    orders = orders_;
}

void Customer::setOrder() {
    orders++;
}


void Menu::setItemCode(int code_){
    ItemCode = code_;
}

void Menu::setItemName(string name_){
    ItemName = name_;
}

void Menu::setItemDescription(string itemDescription_){
    ItemDescription = itemDescription_;
}

void Menu::setCuisineType(string cuisineType_){
    CuisineType = cuisineType_;
}

void Menu::setItemPrice(float price_){
    Price = price_;
}

void Menu::setAvailability(bool available_){
    Availabilty = available_;
}


void OrderDetails::setOrderID(int id_) {
    OrderID = id_;
}

void OrderDetails::setItemName(string name_) {
    ItemNames.push_back(name_);
}

void OrderDetails::setItemPrice(float price_) {
    ItemPrice.push_back(price_);
}

void OrderDetails::setItemtotal(float add_) {
    OrderTotal += add_;
}

void OrderDetails::clearItems() {
    ItemNames.clear();
    ItemPrice.clear();
}


void DeliveryOrder::setDriverID(int id_) {
    DriverID = id_;
}

/**------------------------------ Getters ------------------------------**/

/** Return Staff ID **/
int CompanyStaff::getID() const{
    return StaffID;
}

/** Return Full name **/
string CompanyStaff::getName(){
    return FirstName + " " + LastName;
}

/** Return full Address **/
string CompanyStaff::getAddress(){
    return to_string(HouseNo) + " " + HouseRd + ", " + HouseLocatedCity + ", " + Postcode;
}

/** Return Phone number **/
long long CompanyStaff::getPhoneNumber() const{
    return PhoneNumber;
}

/** Return Email **/
string CompanyStaff::getEmail(){
    return Email;
}

/** Return Gender **/
string CompanyStaff::getGender(){
    return Gender;
}

/** Display Emergency Contact full name and phone number **/
void CompanyStaff::getEmergency(){
    cout << "Name : " << EmergencyContactName << endl;
    cout << "Phone Number : " << EmergencyContactPhoneNumber << endl;
}

void Chef::inputCuisine(string cuisine_){
    CuisineSpeciality = cuisine_;
}

void DeliveryDriver::inputVehicleRegNo(string regNo_){
    VehicleRegistrationNo = regNo_;
}

void DeliveryDriver::inputLicenceNo(string licence_){
    DrivingLicenceNo = licence_;
}


/** Return ID **/
int Customer::getID() const{
    return CustomerID;
}

/** Return Name **/
string Customer::getName(){
    return Name;
}

/** Return Phone number **/
long long Customer::getPhoneNumber() const{
    return phoneNumber;
}

/** Return Address **/
string Customer::getAddress(){
    return Address;
}

int Customer::getOrder() const {
    return orders;
}


int Menu::getItemCode() const{
    return ItemCode;
}

string Menu::getItemName(){
    return ItemName;
}

string Menu::getItemDescription() {
    return ItemDescription;
}

string Menu::getCuisineType(){
    return CuisineType;
}

float Menu::getPrice() const{
    return Price;
}

[[maybe_unused]] string Menu::getAvailability() const{
    if (Availabilty){
        return "Available";
    }
    else {
        return "Unavailable";
    }
}


int OrderDetails::getOrderID() const{
    return OrderID;
}

void OrderDetails::getItemNames(vector<string> &names_){
    for (const auto & ItemName : ItemNames) {
        names_.push_back(ItemName);
    }
}

void OrderDetails::getItemPrices(vector<float> &prices_){
    for (float i : ItemPrice) {
        prices_.push_back(i);
    }
}

float OrderDetails::getTotal() const{
    return OrderTotal;
}


int DeliveryOrder::getDriverID() {
    return DriverID;
}

/** ------------------------- Classes end ------------------------- **/

//Manager tempManager;
//Chef tempChef;
//Receptionist tempReceptionist;
//DeliveryDriver tempDeliveryDriver;
//Customer tempCustomer;
//Menu tempMenu;
//OrderDetails tempOrder;
//DeliveryOrder tempDeliveryOrder;

vector<Manager> manager;
vector<Chef> chef;
vector<Receptionist> receptionist;
vector<DeliveryDriver> deliveryDriver;
vector<Customer> customer;
vector<Menu> menu;
vector<Menu> menuStarters;
vector<Menu> menuMains;
vector<Menu> menuDesserts;
vector<Menu> menuDrinks;
//vector<OrderDetails> order;
vector<DeliveryOrder> deliverOrder;


/** ------------------------- Validations start ------------------------- **/

void errorOutput(){
    cout << "Invalid input, try again!" << endl;
    cin.clear();
    cin.ignore(1000, '\n');
}

template<class input>
void inputVal(input &userIn){
    while (true){
        cin >> userIn;

        if (cin.fail()){
            errorOutput();
        }
        else{
            break;
        }
    }
}

void mainMenuVal(int &selection){
    while (true){
        inputVal(selection);

        if (selection < 0 || selection > 4){
            errorOutput();
        }
        else{
            break;
        }
    }
}

void staffMenuVal(int &selection){
    while (true){
        inputVal(selection);

        if (selection < 0 || selection > 3){
            errorOutput();
        }
        else{
            break;
        }
    }
}

void staffSelectionMenuVal(int &selection, bool staff){
    while (true){
        inputVal(selection);

        if (!staff && (selection < 1 || selection > 4)){
            errorOutput();
        }
        else if (staff && (selection < 1 || selection > 5)){
            errorOutput();
        }
        else{
            break;
        }
    }
}

void oneTwoVal(int &selection){
    while (true){
        inputVal(selection);

        if (selection < 0 || selection > 2){
            errorOutput();
        }
        else{
            break;
        }
    }
}

bool characterCheck(string &check){
    for(const char c : check) {
        if (!isalpha(c) && !isspace(c)) // Checking the characters in the name is only spaces and alphabet
            return false;
    }
    return true;
}

void nameVal(string &name){
    do {
        getline(cin >> ws, name);
        if (!characterCheck(name)){
            cout << "Invalid name. Try again!!!\n";
            continue;
        }
        else{
            break;
        }
    } while (true);
}

void positiveNumVal(int &num){
    while (true){
        inputVal(num);

        if (num < 0){
            errorOutput();
        }
        else{
            break;
        }
    }
}

void addressVal(string &check){
    do {
        getline(cin >> ws, check);
        if (!characterCheck(check)){
            cout << "Invalid Address. Try again!!!\n";
            continue;
        }
        else{
            break;
        }
    } while (true);
}

bool emailValPattern(string &email) {
    const regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return regex_match(email, pattern);
}

void emailVal(string &email_){
    do {
        cin >> email_;
        if (!emailValPattern(email_)){
            cout << "Invalid email. Try again!!!\n";
            continue;
        }
        else{
            break;
        }
    } while (true);
}

void itemTypeVal(int &selection){
    while (true){
        inputVal(selection);

        if (selection < 1 || selection > 4){
            errorOutput();
        }
        else{
            break;
        }
    }
}

/** ------------------------- Validations end ------------------------- **/


/** ------------------------- Menus start ------------------------- **/

int mainMenu(){
    int select;

    cout << setw(15) << setfill(' ') << " " << "Menu" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Create Order" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Menu Items" << endl;
    cout << setw(5) << setfill(' ') << " " << "3 - Staff Details" << endl;
    cout << setw(5) << setfill(' ') << " " << "4 - Customer Details" << endl;
    cout << setw(5) << setfill(' ') << " " << "0 - Exit" << endl;
    mainMenuVal(select);

    return select;
}

int staffMenu(){
    int select;

    cout << setw(10) << setfill(' ') << " " << "staff" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Add staff" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Display staff" << endl;
    cout << setw(5) << setfill(' ') << " " << "3 - Emergency Contacts" << endl;
    cout << setw(5) << setfill(' ') << " " << "0 - Main Menu" << endl;

    staffMenuVal(select);

    return select;
}

int staffSelectionMenu(bool allStaff){
    int select;

    cout << setw(10) << setfill(' ') << " " << "staff" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Manager" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Chef" << endl;
    cout << setw(5) << setfill(' ') << " " << "3 - Receptionist" << endl;
    cout << setw(5) << setfill(' ') << " " << "4 - Delivery Driver" << endl;

    if (allStaff){
        cout << setw(5) << setfill(' ') << " " << "5 - All Staff" << endl;
    }
    staffSelectionMenuVal(select, allStaff);

    return select;
}

int menuItemsMenu(){
    int select;

    cout << setw(15) << setfill(' ') << " " << "Menu" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Add Menu Item" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Display Menu Items" << endl;
    cout << setw(5) << setfill(' ') << " " << "0 - Main Menu" << endl;

    oneTwoVal(select);

    return select;
}

int customerMenu(){
    int select;

    cout << setw(15) << setfill(' ') << " " << "Customer" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Add Customer" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Display Customers" << endl;
    cout << setw(5) << setfill(' ') << " " << "0 - Main Menu" << endl;

    oneTwoVal(select);

    return select;
}

int orderMenu(){
    int select;

    cout << setw(15) << setfill(' ') << " " << "Order Type" << endl;
    cout << setw(5) << setfill(' ') << " " << "1 - Delivery" << endl;
    cout << setw(5) << setfill(' ') << " " << "2 - Collection" << endl;

    oneTwoVal(select);

    return select;
}

/** ------------------------- Menus end ------------------------- **/


/** Input First Name and return **/
string setFirstName(){
    string fName;
    cout << "First Name :";
    nameVal(fName);
    return fName;
}

/** Input Last name and return **/
string setLastName(){
    string lName;
    cout << "Last Name :";
    nameVal(lName);
    return lName;
}

/** Input address and pass by reference **/
void setAddress(int &houseNo, string &houseRoad, string &city, string &postcode){
    cout << "House No :";
    positiveNumVal(houseNo);
    cout << "Road :";
    addressVal(houseRoad);
    cout << "City :";
    addressVal(city);
    cout << "Postcode :"; getline(cin >> ws, postcode);
}

/** Input address and pass by reference **/
void setAddressAndPostcode(string &address){
    cout << "Address :"; getline(cin >> ws, address);
}

/** Input postcode and check the postcode is within delivery range **/
bool setPostcodeAndValidate(){
    string postcode_;

    cout << "Postcode :";
    getline(cin >> ws, postcode_);

    for (const auto & i : POSTCODES) {
        if (postcode_ == i){
            return true;
        }
    }
    return false;
}

/** Input Phone number and return **/
long long setPhoneNumber(){
    long long phoneNum;
    cout << "Phone Number :";
    inputVal(phoneNum);
    return phoneNum;
}

/** Input email and pass by reference**/
void setEmail(string &email){
    cout << "Email :";
    emailVal(email);
}

/** Input gender and pass by reference **/
void setGender(string &gender){
    cout << "Gender :"; cin >> gender;
}

/** display menu item types available, input and return the value  **/
int setItemType(){
    int type;

    cout << "Item Type :" << endl;
    cout << "1 - Starter" << endl;
    cout << "2 - Main" << endl;
    cout << "3 - Dessert" << endl;
    cout << "4 - Drinks" << endl;
    itemTypeVal(type);

    return type;
}

/** Returns the item code  **/
int setItemCode(){
    return MENUITEMS;
}

/** input menu dish name and returns  **/
string setItemName(){
    string name;
    cout << "Dish Name :";
    getline(cin >> ws, name);

    return name;
}

/** input menu dish description and returns  **/
string setItemDescription(){
    string description;

    cout << "Item Description :";
    getline(cin >> ws, description);

    return description;
}

/** input cuisine type of tbe dish and returns  **/
string setItemCuisine(){
    int cuisine;
    cout << "Dish Cuisine Type" << endl;
    cout << "1 - South Asian" << endl;
    cout << "2 - Chinese" << endl;
    oneTwoVal(cuisine);

    if (cuisine == 1){
        return "South Asian";
    }
    else{
        return "Chinese";
    }
}

/** input item price and returns it **/
float setItemPrice(){
    float price;

    cout << "Price :";
    inputVal(price);

    return price;
}

/** Adding the items for the menu **/
void setNewItem(){
    MENUITEMS++;

    int type = setItemType();

    tempMenu.setItemCode(setItemCode());
    tempMenu.setItemName(setItemName());
    tempMenu.setItemDescription(setItemDescription());
    tempMenu.setCuisineType(setItemCuisine());
    tempMenu.setItemPrice(setItemPrice());

    if (type == 1){
        menuStarters.push_back(tempMenu);
    }
    else if (type == 2){
        menuMains.push_back(tempMenu);
    }
    else if (type == 3){
        menuDesserts.push_back(tempMenu);
    }
    else{
        menuDrinks.push_back(tempMenu);
    }
}

/** Add staff to the application **/
void setStaffDetails(int selection){
    int houseNo;
    string houseRoad, city, postcode;
    string email;
    string gender;

    STAFFCOUNT++;

    // Add managers
    if (selection == 1){
        // Staff
        MANAGERCOUNT++;
        tempManager.setStaffId(STAFFCOUNT);
        tempManager.setName(setLastName(), setFirstName());
        setAddress(houseNo, houseRoad, city, postcode);
        tempManager.setAddress(houseNo, houseRoad, city, postcode);
        tempManager.setPhoneNumber(setPhoneNumber());
        setEmail(email);
        tempManager.setEmail(email);
        setGender(gender);
        tempManager.setGender(gender);

        // Emergency
        cout << endl << "Emergency Contact Details" << endl << endl;
        tempManager.setEmergencyContact(setPhoneNumber(), setFirstName());
        manager.push_back(tempManager);

    }

        // Add chefs
    else if (selection == 2){
        // Staff
        CHEFCOUNT++;
        tempChef.setStaffId(STAFFCOUNT);
        tempChef.setName(setLastName(), setFirstName());
        setAddress(houseNo, houseRoad, city, postcode);
        tempChef.setAddress(houseNo, houseRoad, city, postcode);
        tempChef.setPhoneNumber(setPhoneNumber());
        setEmail(email);
        tempChef.setEmail(email);
        setGender(gender);
        tempChef.setGender(gender);
        tempChef.setCuisine();

        // Emergency
        cout << endl << "Emergency Contact Details" << endl << endl;
        tempChef.setEmergencyContact(setPhoneNumber(), setFirstName());
        chef.push_back(tempChef);
    }

        // Add Receptionists
    else if (selection == 3){
        // Staff
        RECEPTIONISTCOUNT++;
        tempReceptionist.setStaffId(STAFFCOUNT);
        tempReceptionist.setName(setLastName(), setFirstName());
        setAddress(houseNo, houseRoad, city, postcode);
        tempReceptionist.setAddress(houseNo, houseRoad, city, postcode);
        tempReceptionist.setPhoneNumber(setPhoneNumber());
        setEmail(email);
        tempReceptionist.setEmail(email);
        setGender(gender);
        tempReceptionist.setGender(gender);

        // Emergency
        cout << endl << "Emergency Contact Details" << endl << endl;
        tempReceptionist.setEmergencyContact(setPhoneNumber(), setFirstName());
        receptionist.push_back(tempReceptionist);
    }

        // Add Delivery Driver
    else{
        // Staff
        DELIVERYDRIVERCOUNT++;
        tempDeliveryDriver.setStaffId(STAFFCOUNT);
        tempDeliveryDriver.setName(setLastName(), setFirstName());
        setAddress(houseNo, houseRoad, city, postcode);
        tempDeliveryDriver.setAddress(houseNo, houseRoad, city, postcode);
        tempDeliveryDriver.setPhoneNumber(setPhoneNumber());
        setEmail(email);
        tempDeliveryDriver.setEmail(email);
        setGender(gender);
        tempDeliveryDriver.setGender(gender);
        tempDeliveryDriver.setDrivingLicenceNo();
        tempDeliveryDriver.setVehicleRegistrationNo();

        // Emergency
        cout << endl << "Emergency Contact Details" << endl << endl;
        tempDeliveryDriver.setEmergencyContact(setPhoneNumber(), setFirstName());
        deliveryDriver.push_back(tempDeliveryDriver);
    }

}

/** Displays the table header of staff details table **/
void staffTableHeader(){
    cout << "|" << setfill(' ') << left << setw(5) << "ID" << "|"
         << setfill(' ') << left << setw(20) << "Name" << "|"
         << setfill(' ') << left << setw(30) << "Email" << "|"
         << setfill(' ') << left << setw(15) << "Phone Number" << "|"
         << setfill(' ') << left << setw(8) << "Gender" << "|"
         << setfill(' ') << left << setw(45) << "Address" << "|" << endl;
}

/** Displays the table header of customer details table **/
void customerTableHeader(){
    cout << "|" << setfill(' ') << left << setw(5) << "ID" << "|"
         << setfill(' ') << left << setw(20) << "Name" << "|"
         << setfill(' ') << left << setw(15) << "Phone Number" << "|"
         << setfill(' ') << left << setw(45) << "Address" << "|"
         << setfill(' ') << left << setw(6) << "orders" << "|" << endl;
}

/** Displays the table header of Menu table **/
void menuTableHeader(){
    cout << "|" << setfill(' ') << left << setw(7) << "Item No" << "|"
         << setfill(' ') << left << setw(50) << "Item Name" << "|"
         << setfill(' ') << left << setw(6) << "Price" << "|" << endl;
}

/** Display stored Staff data **/
void getStaffDetails(int userSelection){
    // Managers
    if (userSelection == 1){
        for (auto & i : manager) {
            cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
                 << setfill(' ') << left << setw(20) << i.getName() << "|"
                 << setfill(' ') << left << setw(30) << i.getEmail() << "|"
                 << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
                 << setfill(' ') << left << setw(8) << i.getGender() << "|"
                 << setfill(' ') << left << setw(45) << i.getAddress() << "|" << endl;
        }
    }

        // Chefs
    else if (userSelection == 2){
        for (auto & i : chef) {
            cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
                 << setfill(' ') << left << setw(20) << i.getName() << "|"
                 << setfill(' ') << left << setw(30) << i.getEmail() << "|"
                 << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
                 << setfill(' ') << left << setw(8) << i.getGender() << "|"
                 << setfill(' ') << left << setw(45) << i.getAddress() << "|" << endl;
        }
    }

        // Receptionists
    else if (userSelection == 3){
        for (auto & i : receptionist) {
            cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
                 << setfill(' ') << left << setw(20) << i.getName() << "|"
                 << setfill(' ') << left << setw(30) << i.getEmail() << "|"
                 << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
                 << setfill(' ') << left << setw(8) << i.getGender() << "|"
                 << setfill(' ') << left << setw(45) << i.getAddress() << "|" << endl;
        }
    }

        // Delivery Drivers
    else if (userSelection == 4){
        for (auto & i : deliveryDriver) {
            cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
                 << setfill(' ') << left << setw(20) << i.getName() << "|"
                 << setfill(' ') << left << setw(30) << i.getEmail() << "|"
                 << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
                 << setfill(' ') << left << setw(8) << i.getGender() << "|"
                 << setfill(' ') << left << setw(45) << i.getAddress() << "|" << endl;
        }
    }

        // All Staff details
    else if (userSelection == 5){
        for (int i = 1; i < 5; i++) {
            getStaffDetails(i);
        }
    }
}

/** Display stored Staff names **/
int getStaffNames(int num){
    int input;
    // Manager names
    if (num == 1){
        for (int i = 0; i < manager.size(); i++) {
            cout << i + 1 << " - " << manager[i].getName() << endl;
        }
    }

        // Chefs names
    else if (num == 2){
        for (int i = 0; i < chef.size(); i++) {
            cout << i + 1 << " - " << chef[i].getName() << endl;
        }
    }

        // Receptionists names
    else if (num == 3){
        for (int i = 0; i < receptionist.size(); i++) {
            cout << i + 1 << " - " << receptionist[i].getName() << endl;
        }
    }

        // Drivers names
    else if (num == 4){
        for (int i = 0; i < deliveryDriver.size(); i++) {
            cout << i + 1 << " - " << deliveryDriver[i].getName() << endl;
        }
    }

    cin >> input;
    return input - 1;
}

/** Display stored Emergency contact details of the selected staff member **/
void getEmergencyContactDetails(int staff, int person){
    cout << endl << "Emergency Contact Details of ";

    if (staff == 1){
        cout << manager[person].getName() << endl;
        manager[person].getEmergency();
    }
    else if (staff == 2){
        cout << chef[person].getName() << endl;
        chef[person].getEmergency();
    }
    else if (staff == 3){
        cout << receptionist[person].getName() << endl;
        receptionist[person].getEmergency();
    }
    else if (staff == 4){
        cout << deliveryDriver[person].getName() << endl;
        deliveryDriver[person].getEmergency();
    }

    cout << endl;
}

/** Display menu items **/
 void getMenuItems(){
    menuTableHeader();

    for (auto & i : menu) {
        cout << "|" << setfill(' ') << left << setw(7) << i.getItemCode() << "|"
             << setfill(' ') << left << setw(50) << i.getItemName() << "|"
             << setfill(' ') << left << setw(6) << i.getPrice() << "|" << endl
             << setfill(' ') << left << setw(9) << " "
             << setfill(' ') << left << setw(45) << i.getItemDescription() << endl << endl;
    }
}

/** Display stored customer details **/
void getCustomerDetails(){
    customerTableHeader();
    /*for (auto & i : customer) {
        cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
             << setfill(' ') << left << setw(20) << i.getName() << "|"
             << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
             << setfill(' ') << left << setw(45) << i.getAddress() << "|" << endl;
    }*/

    for (auto & i : customer) {
        cout << "|" << setfill(' ') << left << setw(5) << i.getID() << "|"
             << setfill(' ') << left << setw(20) << i.getName() << "|"
             << setfill(' ') << left << setw(15) << i.getPhoneNumber() << "|"
             << setfill(' ') << left << setw(45) << i.getAddress() << "|"
             << setfill(' ') << left << setw(6) << i.getOrder() << "|" << endl;
    }
}

/** Add Customers to the application **/
void setCustomerDetails(){
    string House;

    CUSTOMERCOUNT++;
    tempCustomer.setID(CUSTOMERCOUNT);
    tempCustomer.setName(setLastName(), setFirstName());
    setAddressAndPostcode(House);
    tempCustomer.setAddress(House);
    tempCustomer.setPhoneNumber(setPhoneNumber());
    customer.push_back(tempCustomer);
}

bool connectCustomer(long long phone, int &pos){
    for (int i = 0; i < customer.size(); i++) {
        if (phone == customer[i].getPhoneNumber()){
            pos = i;
            return true;
        }
    }

    return false;
}

void setOrder(){
    vector<string> tempItemNames;
    vector<float> tempItemPrices;
    int orderSelection, customerPosition;
    long long number;
    char cus;

    number = setPhoneNumber();

    bool Customer = connectCustomer(number, customerPosition);


    if (!Customer){
        cout << "Customer not existed on the database. Creating a new customer" << endl;
        setCustomerDetails();
        Customer = connectCustomer(number, customerPosition);
    }
    customer[customerPosition].setOrder();



    int selection  = orderMenu();

    ORDERCOUNT++;

    // Delivery
    if (selection == 1){
        string postcode_;

        DELIVERYORDERCOUNT++;

        bool validPostcode = setPostcodeAndValidate();
        if (validPostcode){
            cout << "Assigning Driver" << endl;
            tempDeliveryOrder.setDriverID(getStaffNames(4) - 1);

            tempDeliveryOrder.setOrderID(ORDERCOUNT);

            getMenuItems();
            cout << "Input Item code to add items to the order" << endl;
            cout << "Input 0 to complete the order" << endl;

            do {
                cin >> orderSelection;

                if (orderSelection == 0){
                    break;
                }
                else {
                    tempDeliveryOrder.setItemName(menu[orderSelection - 1].getItemName());
                    tempDeliveryOrder.setItemPrice(menu[orderSelection - 1].getPrice());
                    tempDeliveryOrder.setItemtotal(menu[orderSelection - 1].getPrice());
                }
            } while (true);

            deliverOrder.push_back(tempDeliveryOrder);

            /** Display Delivery order **/
            cout << "----------------Restaurant Name----------------" << endl <<
                 "                 Order No " << ORDERCOUNT << endl << endl;

            cout << "Order ID : " << tempDeliveryOrder.getOrderID() << endl;
            cout << endl << "Items" << endl;

            tempDeliveryOrder.getItemNames(tempItemNames);
            tempDeliveryOrder.getItemPrices(tempItemPrices);

            for (int i = 0; i < tempItemNames.size(); i++) {
                cout << setfill(' ') << left << setw(30) << tempItemNames[i] << setfill(' ') << left << setw(5) << tempItemPrices[i] /*<< setfill(' ') << left << setw(20)*/ << endl;
            }


            cout  << setfill(' ') << left << setw(30) << "Total of items $: " << tempDeliveryOrder.getTotal() << endl;
            cout << endl << setfill(' ') << left << setw(30) << "Delivery Cost $: " << "1" << endl;
            cout << setfill(' ') << left << setw(30) << "Total $: " << tempDeliveryOrder.getTotal() + 1 << endl << endl << endl;
            REPORT_TOTAL += tempDeliveryOrder.getTotal() + 1;

            tempDeliveryOrder.clearItems();
        }
        else{
            cout << "Incorrect postcode or out of delivering area" << endl << endl;
        }



    }

    // Collection
    else{
        COLLECTIONORDERCOUNT++;

        tempOrder.setOrderID(ORDERCOUNT);

        getMenuItems();
        cout << "Input Item code to add items to the order" << endl;
        cout << "Input 0 to complete the order" << endl;

        do {
            cin >> orderSelection;

            if (orderSelection == 0){
                break;
            }
            else {
                tempOrder.setItemName(menu[orderSelection - 1].getItemName());
                tempOrder.setItemPrice(menu[orderSelection - 1].getPrice());
                tempOrder.setItemtotal(menu[orderSelection - 1].getPrice());
            }
        } while (true);


        /** Display Collection order **/
        cout << "----------------Restaurant Name----------------" << endl <<
             "                 Order No " << ORDERCOUNT << endl << endl;

        cout << "Order ID : " << tempOrder.getOrderID() << endl;
        cout << endl << "Items" << endl;

        tempOrder.getItemNames(tempItemNames);
        tempOrder.getItemPrices(tempItemPrices);

        for (int i = 0; i < tempItemNames.size(); i++) {
            cout << setfill(' ') << left << setw(30) << tempItemNames[i] << setfill(' ') << left << setw(5) << tempItemPrices[i] /*<< setfill(' ') << left << setw(20)*/ << endl;
        }


        cout  << setfill(' ') << left << setw(30) << "Total of items $: " << tempOrder.getTotal() << endl;
        cout << endl << setfill(' ') << left << setw(30) << "Delivery Cost $: " << "1" << endl;
        cout << setfill(' ') << left << setw(30) << "Total $: " << tempOrder.getTotal() + 1 << endl << endl << endl;

        REPORT_TOTAL += tempOrder.getTotal() + 1;

        tempOrder.clearItems();

    }


    // Display section


}

/** Read staff details from the file **/
void readDataForStaff(){
    string staffType;
    string temp, tempTwo, tempThree, tempFour, tempFirstName, tempLastName;
    long long num;

    ifstream myFile;

    myFile.open("staffMemberDetails.txt");
    if (myFile.is_open()){
        while (!myFile.eof()){
            STAFFCOUNT++;

            getline(myFile, staffType, '|');

            // Input Managers
            if (staffType == "1"){
                MANAGERCOUNT++;

                // ID
                getline(myFile, temp, '|');
                tempManager.setStaffId(stoi(temp));

                // Name
                myFile >> tempFirstName;
                getline(myFile, tempLastName, '|');
                tempManager.setName(tempLastName, tempFirstName);

                // Email
                getline(myFile, temp, '|');
                tempManager.setEmail(temp);

                // Phone Number
                getline(myFile, temp, '|');
                num = stoll(temp);
                tempManager.setPhoneNumber(num);

                // Gender
                getline(myFile, temp, '|');
                tempManager.setGender(temp);

                // Address
                getline(myFile, temp, ',');
                getline(myFile, tempTwo, ',');
                getline(myFile, tempThree, ',');
                getline(myFile, tempFour, '|');
                tempManager.setAddress(stoi(temp), tempTwo, tempThree, tempFour);

                // Emergency Contact Name
                getline(myFile, temp, '|');
                getline(myFile, tempTwo, '\n');
                tempManager.setEmergencyContact(stoll(tempTwo), temp);

                manager.push_back(tempManager);
            }

                // Input Chefs
            else if (staffType == "2"){
                CHEFCOUNT++;

                // ID
                getline(myFile, temp, '|');
                tempChef.setStaffId(stoi(temp));

                // Name
                myFile >> tempFirstName;
                getline(myFile, tempLastName, '|');
                tempChef.setName(tempLastName, tempFirstName);

                // Email
                getline(myFile, temp, '|');
                tempChef.setEmail(temp);

                // Phone Number
                getline(myFile, temp, '|');
                num = stoll(temp);
                tempChef.setPhoneNumber(num);

                // Gender
                getline(myFile, temp, '|');
                tempChef.setGender(temp);

                // Address
                getline(myFile, temp, ',');
                getline(myFile, tempTwo, ',');
                getline(myFile, tempThree, ',');
                getline(myFile, tempFour, '|');
                tempChef.setAddress(stoi(temp), tempTwo, tempThree, tempFour);

                // Emergency Contact Name
                getline(myFile, temp, '|');
                getline(myFile, tempTwo, '|');
                tempChef.setEmergencyContact(stoll(tempTwo), temp);

                //Cuisine Type
                getline(myFile, temp, '\n');
                tempChef.inputCuisine(temp);

                chef.push_back(tempChef);
            }

                // Input Receptionists
            else if (staffType == "3"){
                RECEPTIONISTCOUNT++;

                // ID
                getline(myFile, temp, '|');
                tempReceptionist.setStaffId(stoi(temp));

                // Name
                myFile >> tempFirstName;
                getline(myFile, tempLastName, '|');
                tempReceptionist.setName(tempLastName, tempFirstName);

                // Email
                getline(myFile, temp, '|');
                tempReceptionist.setEmail(temp);

                // Phone Number
                getline(myFile, temp, '|');
                num = stoll(temp);
                tempReceptionist.setPhoneNumber(num);

                // Gender
                getline(myFile, temp, '|');
                tempReceptionist.setGender(temp);

                // Address
                getline(myFile, temp, ',');
                getline(myFile, tempTwo, ',');
                getline(myFile, tempThree, ',');
                getline(myFile, tempFour, '|');
                tempReceptionist.setAddress(stoi(temp), tempTwo, tempThree, tempFour);

                // Emergency Contact Name
                getline(myFile, temp, '|');
                getline(myFile, tempTwo, '\n');
                tempReceptionist.setEmergencyContact(stoll(tempTwo), temp);

                receptionist.push_back(tempReceptionist);
            }

                // Input Delivery Drivers
            else if (staffType == "4"){
                DELIVERYDRIVERCOUNT++;

                // ID
                getline(myFile, temp, '|');
                tempDeliveryDriver.setStaffId(stoi(temp));

                // Name
                myFile >> tempFirstName;
                getline(myFile, tempLastName, '|');
                tempDeliveryDriver.setName(tempLastName, tempFirstName);

                // Email
                getline(myFile, temp, '|');
                tempDeliveryDriver.setEmail(temp);

                // Phone Number
                getline(myFile, temp, '|');
                num = stoll(temp);
                tempDeliveryDriver.setPhoneNumber(num);

                // Gender
                getline(myFile, temp, '|');
                tempDeliveryDriver.setGender(temp);

                // Address
                getline(myFile, temp, ',');
                getline(myFile, tempTwo, ',');
                getline(myFile, tempThree, ',');
                getline(myFile, tempFour, '|');
                tempDeliveryDriver.setAddress(stoi(temp), tempTwo, tempThree, tempFour);

                // Emergency Contact Name
                getline(myFile, temp, '|');
                getline(myFile, tempTwo, '|');
                tempDeliveryDriver.setEmergencyContact(stoll(tempTwo), temp);

                //Vehicle registration No
                getline(myFile, temp, '|');
                tempDeliveryDriver.inputVehicleRegNo(temp);

                //Licence No
                getline(myFile, temp, '\n');
                tempDeliveryDriver.inputLicenceNo(temp);

                deliveryDriver.push_back(tempDeliveryDriver);
            }
        }
    }
    myFile.close();
}

/** Read menu details from the file **/
void readDataForMenu(){
    string temp;
    string type, type2;

    ifstream myFile;

    myFile.open("menuItems.txt");
    if (myFile.is_open()){
        while (!myFile.eof()){
            MENUITEMS++;

            // Menu item type
            getline(myFile, type, '|');

            // Get Item ID
            getline(myFile, type, '|');
            tempMenu.setItemCode(MENUITEMS);

            // Get Item Name
            getline(myFile, temp, '|');
            tempMenu.setItemName(temp);

            // Get Item Cuisine Type
            getline(myFile, temp, '|');

            // Set Item Cuisine Type
            if (stoi(temp) == 1){
                tempMenu.setCuisineType("South Asian");
            }
            else if (stoi(temp) == 2){
                tempMenu.setCuisineType("Chinese");
            }

            // Set Item Description
            getline(myFile, temp, '|');
            tempMenu.setItemDescription(temp);


            // Set Item Price
            getline(myFile, temp, '|');
            tempMenu.setItemPrice(stof(temp));

            // set Availability
            getline(myFile, temp, '\n');
            if (temp == "1"){
                tempMenu.setAvailability(true);
            }
            else{
                tempMenu.setAvailability(false);
            }

            menu.push_back(tempMenu);
        }
    }
    myFile.close();
}

/** Read customer details from the file **/
void readDataForCustomers(){
    string temp;

    ifstream myFile;

    myFile.open("customerDetails.txt");
    if (myFile.is_open()){
        while (!myFile.eof()){
            CUSTOMERCOUNT++;

            // Get ID
            getline(myFile, temp, '|');
            tempCustomer.setID(stoi(temp));

            // Get Name
            getline(myFile, temp, '|');
            tempCustomer.setname(temp);

            // Get Phone Number
            getline(myFile, temp, '|');
            tempCustomer.setPhoneNumber(stoll(temp));

            // Get Address
            getline(myFile, temp, '|');
            tempCustomer.setAddress(temp);

            // Get Orders
            getline(myFile, temp, '\n');
            tempCustomer.setOrders(stoi(temp));

            customer.push_back(tempCustomer);
        }
    }
    myFile.close();

}

/** Read valid postcodes from the file **/
void readValidPostcodes(){
    string temp;

    ifstream myFile;

    myFile.open("postcodes.txt");
    if (myFile.is_open()){
        while (!myFile.eof()){
            getline(myFile, temp);
            POSTCODES.push_back(temp);
        }
    }
    myFile.close();
}

/** Read data from files **/
void readDataFromFiles(){
    readDataForStaff();
    readDataForMenu();
    readDataForCustomers();
    readValidPostcodes();
}

/** report log **/
void getLog(){
    cout << "End of log report" << endl;
    cout << "Total Orders :" << ORDERCOUNT << endl;
    cout << "Total Delivery Orders :" << DELIVERYORDERCOUNT << endl;
    cout << "Total Collection Orders :" << COLLECTIONORDERCOUNT << endl;
    cout << "Total Income : " << REPORT_TOTAL << endl;

}


int main(){

    //username();
    //password();
    readDataFromFiles();  // Import Data

    do {
        bool display = false;
        int selection = mainMenu();
        system("cls");

        // Create Order
        if (selection == 1){
            setOrder();
            system("cls");
        }

        // Menu Items
        else if (selection == 2){
            int selection2 = menuItemsMenu();
            system("cls");

            // Add menu items
            if (selection2 == 1){
                setNewItem();
            }

                // Display menu Items
            else if (selection2 == 2){
                getMenuItems();
                system("pause");
            }
            
            system("cls");
        }

        // Staff Details
        else if (selection == 3){
            int selection2 = staffMenu();
            system("cls");

            // Add Staff
            if (selection2 == 1){
                int staffSelect = staffSelectionMenu(display);
                setStaffDetails(staffSelect);
            }

                // Display Staff
            else if (selection2 == 2){
                display = true;
                int staffSelect = staffSelectionMenu(display);
                staffTableHeader();
                getStaffDetails(staffSelect);
                system("pause");
            }

                // Display Emergency Contact
            else if (selection2 == 3){
                int staffSelect = staffSelectionMenu(display);
                // Display names
                int emergencyStaff = getStaffNames(staffSelect);
                getEmergencyContactDetails(staffSelect, emergencyStaff);
                system("pause");
            }
            system("cls");
        }

        // Customer Details
        else if (selection == 4){
            int selection2 = customerMenu();
            system("cls");

            // Add customers
            if (selection2 == 1){
                setCustomerDetails();
            }

                // Display Customers
            else if (selection2 == 2){
                getCustomerDetails();
                system("pause");
            }
            system("cls");
        }


        //Exit
        else if (selection == 0){
            getLog();
            system("pause");
            break;
        }

    } while (true);


    return 0;
}