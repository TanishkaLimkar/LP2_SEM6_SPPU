// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// class Product
// {
// public:
//     int id, price, battery;
//     string type, name;

//     Product(int id, string name, int price, int battery, string type)
//     {
//         this->id = id;
//         this->price = price;
//         this->battery = battery;
//         this->name = name;
//         this->type = type;
//     }
//     void display()
//     {
//         cout << " | " << id << " | " << name << " | " << price << " | " << battery << "mAh" << " | " << type << " | " << endl;
//     }
//     void displayShort()
//     {
//         cout << " | " << id << " | " << name << " | " << endl;
//     }

//     int getId()
//     {
//         return id;
//     }
//     int getPrice()
//     {
//         return price;
//     }
//     int getBattery
//     {
//         return battery;
//     }
//     string getName()
//     {
//         return name;
//     }
//     string getType()
//     {
//         return type;
//     }
// };

// vector<Product> products;
// vector<string> cart;

// void initializeProducts()
// {
//     products.push_back(Product(1, "IPHONE", 90000, 700, "Mobile"));
//     products.push_back(Product(2, "SAMSUNG", 80000, 800, "Mobile"));
//     products.push_back(Product(3, "OPPO", 70000, 200, "Mobile"));
//     products.push_back(Product(4, "IPHONE PRO", 190000, 1700, "Laptop"));
//     products.push_back(Product(5, "IPHONE PRO", 390000, 3700, "Laptop"));
//     products.push_back(Product(6, "IPHONE PRO", 290000, 2700, "Laptop"));
// }

// void getProductsByType(string type)
// {
//     for (Product product : products)
//     {
//         if (product.getType() == type)
//         {
//             product.displayShort();
//         }
//     }
// }

// void getProductDetails(string name, string category)
// {
//     for (Product product : products)
//     {
//         if (product.getName() == name)
//         {
//             if (category == "Price" || category == "price")
//             {
//                 cout << "Price: " << product.getPrice() << endl;
//             }
//             else if (category == "Battery" || category == "battery")
//             {
//                 cout << "Battery: " << product.getBattery() << endl;
//             }
//             else if (category == "Type" || category == "type")
//             {
//                 cout << "Type: " << product.getType() << endl;
//             }
//         }
//     }
// }

// void addToCart(string name)
// {
//     for (Product product : products)
//     {
//         if (product.getName() == name)
//         {
//             cart.push_back(product.getName());
//             cout << "Added to cart!" << endl;
//         }
//     }
// }

// void viewCart()
// {
//     for (string item : cart)
//     {
//         cout << "\n-----------------\n";
//         cout << item << endl;
//         cout << "\n-----------------\n";
//     }
// }
// int main()
// {
//     initializeProducts();
//     std::cout << "Product chatbot.....How may I help you??" << endl;
//     while (true)
//     {
//         cout << "1. View Mobile" << endl;
//         cout << "2. View Laptop" << endl;
//         cout << "Tell your choice:";
//         string choice;
//         cin >> choice;
//         if (choice == "Mobile")
//         {
//             getProductsByType("Mobile");
//             cout << "Enter the mobile you want to view ";
//             string mobileName, detailChoice;
//             cin >> mobileName;

//             cout << "Enter \n1. Price\n2. Battery\n3. Type\n";
//             cin >> detailChoice;
//             getProductDetails(mobileName, detailChoice);
//             cout << "Enter \n1. Price\n2. Battery\n3. Type\n";
//             cin >> detailChoice;
//             getProductDetails(mobileName, detailChoice);

//             cout << "Want to add in cart?(y/n)";
//             char answer;
//             cin >> answer; // Fixed: You need to read the input
//             if (answer == 'Y' || answer == 'y')
//             {
//                 addToCart(mobileName);
//             }

//             cout << "Want to view cart?(y/n)";
//             char answerCart;
//             cin >> answerCart; // Fixed: You need to read the input
//             if (answerCart == 'Y' || answerCart == 'y')
//             {
//                 viewCart();
//             }
//             else
//             {
//                 cout << "Exiting...";
//                 break; // Exiting the loop if the user doesn't want to view the cart
//             }
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    string type;
    int id;
    int battery;
    int price;

    Product(int id, string name, string type, int battery, int price)
    {
        this->id = id;
        this->name = name;
        this->type = type;
        this->battery = battery;
        this->price = price;
    }

    void display()
    {
        cout << " | " << id << " | " << name << " | " << type << " | " << battery << "mah" << " | " << price << " | " << endl;
    }

    void display_short()
    {
        cout << " | " << id << " | " << name << " | " << endl;
    }

    int getid()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string gettype()
    {
        return type;
    }
    int getbattery()
    {
        return battery;
    }
    int getprice()
    {
        return price;
    }
};

vector<Product> products;
vector<string> cart;

void initializeProducts()
{
    products.push_back(Product(1, "Iphone15", "Mobile", 4000, 80000));
    products.push_back(Product(2, "Iphone14", "Mobile", 3070, 80000));
    products.push_back(Product(3, "Iphone13", "Mobile", 3678, 80000));

    products.push_back(Product(4, "Hp", "Laptop", 3000, 100000));
    products.push_back(Product(5, "Hp2", "Laptop", 5600, 107000));
}

void getProductByType(string type)
{
    for (Product p : products)
    {
        if (p.gettype() == type)
        {
            p.display_short();
        }
    }
}

void getProductDetails(string name, string category)
{
    for (Product p : products)
    {
        if (p.getName() == name)
        {
            if (category == "price" || category == "Price")
            {
                cout << "Price : " << p.getprice() << endl;
            }
            else if (category == "battery" || category == "Battery")
            {
                cout << "Battery : " << p.getbattery() << endl;
            }
            else if (category == "type" || category == "Type")
            {
                cout << "Type : " << p.gettype() << endl;
            }
        }
    }
}

void addToCart(string name)
{
    for (Product p : products)
    {
        if (p.getName() == name)
        {
            cart.push_back(p.getName());
            cout << "ITEM ADDED TO CART !!" << endl;
        }
    }
}

void view_cart()
{
    for (string item : cart)
    {
        cout << item << endl;
    }
}

int main()
{

    initializeProducts();

    cout << "HELLO THIS IS PRODUCT CHATBOT !! HOW MAY I HELP YOU ?" << endl;

    while (true)
    {
        cout << "ITEM LIST" << endl;
        cout << "1.MOBILE " << endl;
        cout << "2.LAPTOP " << endl;
        cout << "SELECT THE ITEM NAME: " << endl;
        string choice;
        cin >> choice;

        if (choice == "Mobile")
        {
            getProductByType("Mobile");
            string mobilename, detailchoice;

            cout << "Do you want to see more details of the product(y/n)" << endl;
            char c;
            cin >> c;
            cout << "Enter the mobile name : " << endl;
            cin >> mobilename;
            if (c == 'y' || c == 'Y')
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << "DETAILS :" << endl;
                    cout << "1.BATTERY" << endl;
                    cout << "2.PRICE" << endl;
                    cout << "3.TYPE" << endl;

                    cout << "Enter the specification you wish to check :" << endl;
                    cin >> detailchoice;
                    getProductDetails(mobilename, detailchoice);
                }
            }

            cout << "DO YOU WANT TO ADD THE ITEM TO CART (y,n)??" << endl;
            char c1;
            cin >> c1;
            if (c1 == 'y' || c1 == 'Y')
            {
                addToCart(mobilename);
            }

            cout << "DO YOU WISH TO VIEW CART (y,n) ?" << endl;
            char c2;
            cin >> c2;
            if (c2 == 'y' || c2 == 'Y')
            {
                view_cart();
            }
            else
            {
                cout << "EXITING..........." << endl;
                break;
            }
        }
    }
}
