/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


struct Shoe
{
    Shoe();
    std::string brand;
    double size;
    std::string color;
    std::string condition;
    std::string securingMethod;

    void putOn ( std::string firstShoe = "R", bool leftFirst = true);
    void takeOff ( std::string firstShoe = "R", bool leftFirst = true );
    void throwAway ( bool donate = false );
};

Shoe::Shoe()
{
    brand = "Nike";
    size = 12.5;
    color = "white";
    condition = "good";
    securingMethod = "velcro";
}

void Shoe::putOn(std::string firstShoe, bool leftFirst) 
{
    if (leftFirst)
    {
        firstShoe = "L";
    }
}

void Shoe::takeOff(std::string firstShoe, bool leftFirst) 
{
    if (leftFirst)
    {
        firstShoe = "L";
    }
}

void Shoe::throwAway(bool donate) 
{
    if (condition == "good")
    {
        donate = true;
    }
    std::cout << "Is this shoe alright to donate? " << (donate ? "Yes" : "No") << "\n";
}

struct Wurlitzer
{
    Wurlitzer();
    int volumeLevel;
    double vibratoAmount;
    std::string model;
    std::string condition;
    int numKeys;
    int output;
    bool on;

    void changeVolume ( int knobPosition );
    void play ( int note = 23 );
    void power ( bool switchPosition = true );
};

Wurlitzer::Wurlitzer()
{
    volumeLevel = 6;
    vibratoAmount = .5;
    model = "200a";
    condition = "good";
    numKeys = 49;
    output = 23;
    on = false;
}

void Wurlitzer::changeVolume( int knobPosition ) 
{
    volumeLevel = knobPosition;
    std::cout << "Knob Position is: " << knobPosition << "\n";
}

void Wurlitzer::play( int note ) 
{
    output = note;
}

void Wurlitzer::power( bool switchPosition ) 
{
    on = switchPosition;
}

struct ElectricBass
{
    ElectricBass();
    int numStrings;
    std::string pickup;
    std::string brand;
    std::string model;
    int yearMade;
    int output;
    int cost;
    int timeSinceRestrung;

    void play ( int note =  18 );
    void sold ( int price = 1200 );
    void restring ( bool restring = true );
};

ElectricBass::ElectricBass()
{
    numStrings = 4;
    pickup = "precision";
    brand = "fender";
    model = "precision";
    yearMade = 1974;
    output = 23;
    cost = 1544;
    timeSinceRestrung = 13;
}

void ElectricBass::play( int note ) 
{
    output = note;
}

void ElectricBass::sold( int price ) 
{
    cost = price;
    std::cout << "This Bass was sold for $" << price << "\n";
}

void ElectricBass::restring( bool restring ) 
{
    if (restring)
    {
        timeSinceRestrung = 0;
    }
}

struct City
{
    City();
    int population;
    float size;
    double GDP;
    int averageAge;
    std::string country;
    bool party1InCharge;
    int buildingsToBeRepaired;
    int capital;

    void vote (int party1Votes = 13876, int party2Votes = 43786 );
    void naturalDisaster ( int percentOfPropertiesDamaged = 47 );
    void buildTransportation ( int cost = 2433244 );
};

City::City()
{
    population = 4649231;
    size = 34.65f;
    GDP = 65569340958.98;
    averageAge = 43;
    country = "New Zeland";
    party1InCharge = true;
    buildingsToBeRepaired = 1;
    capital = 14414414;
}

void City::vote( int party1Votes, int party2Votes ) 
{
    if (party1Votes > party2Votes)
    {
        party1InCharge = true;
    }
    else
    {
        party1InCharge = false;
    }
}

void City::naturalDisaster( int percentOfPropertiesDamaged ) 
{
    buildingsToBeRepaired = percentOfPropertiesDamaged;
}

void City::buildTransportation( int cost ) 
{
    capital -= cost;
}

struct Bedroom
{
    Bedroom();
    std::string name;
    float bedSize;
    std::string floor;
    int floorSpace;
    int lastCleaned;
    int slept;
    int piecesOfFurnature;

    struct Bed
    {
        Bed();
        int height;
        int pillows;
        std::string headboardMaterial;
        std::string size;
        int bedAge;
        std::string lastInBed;
        std::string company;
        int sheetsLastCleaned;

        void makeBed ( bool newSheets = true);
        void sleepInBed (std::string sleeper = "jeff");
        void newMatress ( std::string brand = "tempurpedic");
    };
    void sleepIn ( int timeAwake = 843, int timeAsleep = 98);
    void clean ( bool vacumed = true );
    void rearange ( int newFurnature = 1 );
};

Bedroom::Bed::Bed()
{
    height = 14;
    pillows = 4;
    headboardMaterial = "maple";
    size = "full";
    bedAge = 3;
    lastInBed = "jeff";
    company = "tempurpedic";
    sheetsLastCleaned = 14;
}

Bedroom::Bedroom()
{
    name = "Josh";
    bedSize = 9.23f;
    floor = "maple";
    floorSpace = 43;
    lastCleaned = 14;
    slept = 480;
    piecesOfFurnature = 6;
}

void Bedroom::Bed::makeBed( bool newSheets ) 
{
    if(newSheets)
    {
        sheetsLastCleaned = 0;
    }
}

void Bedroom::Bed::sleepInBed( std::string sleeper) 
{
    lastInBed = sleeper;
}

void Bedroom::Bed::newMatress(std::string brand) 
{
    bedAge = 0;
    company = brand;
}

void Bedroom::sleepIn( int timeAwake, int timeAsleep ) 
{
    slept = (timeAwake - timeAsleep);
}

void Bedroom::clean( bool vacumed ) 
{
    if(vacumed)
    {
        lastCleaned = 0;
    }
}

void Bedroom::rearange( int newFurnature ) 
{
    piecesOfFurnature += newFurnature;
}

struct Kitchen
{
    Kitchen();
    int cabinets;
    std::string cookingUtilities;
    int dirtyDishes;
    int fridgeSpace;
    int windows;
    bool stoveToBeCleaned;

    void cook ( bool stoveUsed = true );
    void fridgeRestock ( int foodsize = 8 );
    void clean ( bool dishwasherRan = false );
};

Kitchen::Kitchen()
{
    cabinets = 18;
    cookingUtilities = "pan";
    dirtyDishes = 8;
    fridgeSpace = 48;
    windows = 9;
    stoveToBeCleaned = true;
}

void Kitchen::cook( bool stoveUsed ) 
{
    if(stoveUsed)
    {
        stoveToBeCleaned = true;
    }
}

void Kitchen::fridgeRestock( int foodsize ) 
{
    fridgeSpace -= foodsize;
}

void Kitchen::clean( bool dishwasherRan ) 
{
    if(dishwasherRan)
    {
        dirtyDishes = false;
    }
}

struct Bathroom
{
    Bathroom();
    int mirrorSize;
    int numSink;
    int counterItems;
    int timeSinceCleaned;
    int toiletHeight;
    int sinceShowerUsed;
    int sinceToiletUsed;
    bool changeSeat;
    bool readyForGuests;

    struct Shower
    {
        Shower();
        int headHeight;
        bool inBath;
        std::string enclosure;
        float waterTemp;
        int showerlength;
        bool cleanShower;

        float waterAmount ( float handlePosition = 0.5f  );
        void adjustWaterTemp (float coldPosition = 0.32f , float hotPosition = 0.69f);
        void drainClog ( bool clogged = false);
    };
    void useShower ( Shower Shower );
    void useToilet ( bool seatDownn = false );
    void clean ( bool bleachUsed = false );
};

Bathroom::Bathroom()
{
    mirrorSize = 8;
    numSink = 2;
    counterItems = 8;
    timeSinceCleaned = 5;
    toiletHeight = 17;
    sinceShowerUsed = 0;
    sinceToiletUsed = 3;
    changeSeat = false;
    readyForGuests = false;
}

Bathroom::Shower::Shower()
{
    headHeight = 64;
    inBath = false;
    enclosure = "curtain";
    waterTemp = 102;
    showerlength = 12;
    cleanShower = false;
}

float Bathroom::Shower::waterAmount( float handlePosition ) 
{
    return (handlePosition * 24);
}

void Bathroom::Shower::adjustWaterTemp( float coldPosition, float hotPosition ) 
{
    waterTemp = ((coldPosition - hotPosition) * 43);
}

void Bathroom::Shower::drainClog( bool clogged ) 
{
    if (clogged)
    {
        cleanShower = true;
    }
}

void Bathroom::useShower( Shower shower ) 
{
    sinceShowerUsed = 0;
    shower.waterTemp = 54;
}

void Bathroom::useToilet( bool seatDownn ) 
{
    if(seatDownn)
    {
        changeSeat = true;
    }
}

void Bathroom::clean( bool bleachUsed ) 
{
    if(bleachUsed)
    {
        readyForGuests = true;
    }
}

struct LivingRoom
{
    LivingRoom();
    int sittingPlaces;
    int TVsize;
    int windows;
    std::string wallColor;
    int doors;
    int piecesOfFurnature;
    bool sataliteWatched;
    int timeSincePainted;

    void useTV ( bool netflix = true );
    void paintRoom ( bool newcolor = false );
    void rearange ( int newfurnature = 1);
};

LivingRoom::LivingRoom()
{
    sittingPlaces = 3;
    TVsize = 42;
    windows = 3;
    wallColor = "red";
    doors = 3;
    piecesOfFurnature = 5;
    sataliteWatched = false;
    timeSincePainted = 43;
}

void LivingRoom::useTV( bool netflix ) 
{
    sataliteWatched = !netflix;
}

void LivingRoom::paintRoom( bool newcolor ) 
{
    if(newcolor)
    {
        timeSincePainted = 0;
    }
}

void LivingRoom::rearange( int newFurnature ) 
{
    piecesOfFurnature += newFurnature;
}

struct Garage
{
    Garage();
    int carSpots = 1;
    int doors = 1;
    int windows = 8;
    int items = 41;
    int lights = 2;
    int whereToPark = 1;
    int openSource = 2; 

    void parkCar ( bool spotAOpen = true, bool spotBOpen = true, bool spotCOpen = true );
    void doorOpen ( bool fromCar = true );
    void altUsage ( std::string garageUsage = "art studio");
};

Garage::Garage()
{
    carSpots = 1;
    doors = 1;
    windows = 8;
    items = 41;
    lights = 2;
    whereToPark = 1;
    openSource = 2; 
}

void Garage::parkCar( bool spotAOpen, bool spotBOpen, bool spotCOpen ) 
{
    if(spotCOpen)
    {
        whereToPark = 3;
    }
    if(spotBOpen)
    {
        whereToPark = 2;
    }
    if(spotAOpen)
    {
        whereToPark = 1;
    }

}

void Garage::doorOpen( bool fromCar ) 
{
    if (fromCar)
    {
            openSource = 2;
    }
}

void Garage::altUsage(std::string garageUsage) 
{
    if(garageUsage != "park car")
    {
        carSpots = 0;
    }
}

struct House
{
    House();
    Bedroom sarasRoom;
    Kitchen cookery;
    Bathroom lavatory;
    LivingRoom familyRoom;
    Garage storage;
    int rooms;
    int value;
    int newWalls;


    void addRoom ( int numNewRooms );
    void sellHouse ( int soldPrice = 804398 );
    void demolish ( int originalWallsRemaining = 1, int totalWalls = 4 );
};

House::House()
{
    rooms = 3;
    value = 430300;
    newWalls = 5;
}

void House::addRoom( int numNewRooms ) 
{
    rooms += numNewRooms;
}

void House::sellHouse( int soldPrice ) 
{
    value = soldPrice;
}

void House::demolish( int originalWallsRemaining, int totalWalls ) 
{
    newWalls = (totalWalls - originalWallsRemaining);
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
    Shoe blazer, airforce1;
    Wurlitzer red, tan;
    ElectricBass jaguar, precision;
    City losAngeles;
    Bedroom myRoom, brothersRoom;
    Bedroom::Bed myBed;
    Kitchen cookery;
    Bathroom myBathroom, brothersBathroom;
    Bathroom::Shower myShower;
    LivingRoom frontRoom;
    Garage carSpot;
    House myHouse;

    jaguar.play(24);
    tan.power(true);
    frontRoom.rearange(5);
    myShower.adjustWaterTemp(0.47f, 0.94f);
    losAngeles.vote(26486434, 4328763);
    cookery.clean(true);
    myHouse.addRoom(5);
    carSpot.parkCar(false, true, false);
    blazer.putOn("L", false);
    frontRoom.paintRoom(true);



    std::cout << "Should I clean my Room? " << (myRoom.lastCleaned > 7 ? "Yes" : "No") << "\n";

    std::cout << "Did I sleep to long? " << (myRoom.slept > 8 ? "Yes" : "No") << "\n";

    std::cout << "good to go!" << std::endl;
}
