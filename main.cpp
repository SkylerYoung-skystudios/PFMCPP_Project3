/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 1) Add a constructor for each User-Defined-Type.
 
 2) amend some of your UDT's member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function

 4) call some of your UDT's amended member functions in main().
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





struct Shoe
{
    std::string brand = "Nike";
    double size = 12.5;
    std::string color = "white";
    std::string condition = "good";
    std::string securingMethod = "velcro";

    void putOn ( std::string firstShoe = "R", bool leftFirst = true);
    void takeOff ( std::string firstShoe = "R", bool leftFirst = true );
    void throwAway ( bool donate = false );
};

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
}

struct Wurlitzer
{
    int volumeLevel = 6;
    double vibratoAmount = .5;
    std::string model = "200a";
    std::string condition = "good";
    int numKeys = 49;
    int output = 23;
    bool on = false;

    void changeVolume ( int knobPosition );
    void play ( int note = 23 );
    void power ( bool switchPosition = true );
};

void Wurlitzer::changeVolume( int knobPosition ) 
{
    volumeLevel = knobPosition;
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
    int numStrings = 4;
    std::string pickup = "precision";
    std::string brand = "fender";
    std::string model = "precision";
    int yearMade = 1974;
    int output = 23;
    int cost = 1544;
    int timeSinceRestrung = 13;

    void play ( int note =  18 );
    void sold ( int price = 1200 );
    void restring ( bool restring = true );
};

void ElectricBass::play( int note ) 
{
    output = note;
}

void ElectricBass::sold( int price ) 
{
    cost = price;
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
    int population = 4649231;
    float size = 34.65f;
    double GDP = 65569340958.98;
    int averageAge = 43;
    std::string country = "New Zeland";
    bool party1InCharge = true;
    int buildingsToBeRepaired = 1;
    int capital = 14414414;

    void vote (int party1Votes = 13876, int party2Votes = 43786 );
    void naturalDisaster ( int percentOfPropertiesDamaged = 47 );
    void buildTransportation ( int cost = 2433244 );
};

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
    std::string name = "Josh";
    float bedSize = 9.23f;
    std::string floor = "maple";
    int floorSpace = 43;
    int lastCleaned = 14;
    int slept = 480;
    int piecesOfFurnature = 6;

    struct Bed
    {
        int height = 14;
        int pillows = 4;
        std::string headboardMaterial = "maple";
        std::string size = "full";
        int bedAge = 3;
        std::string lastInBed = "jeff";
        std::string company = "tempurpedic";
        int sheetsLastCleaned = 14;

        void makeBed ( bool newSheets = true);
        void sleepInBed (std::string sleeper = "jeff");
        void newMatress ( std::string brand = "tempurpedic");
    };
    void sleepIn ( int timeAwake = 843, int timeAsleep = 98);
    void clean ( bool vacumed = true );
    void rearange ( int newFurnature = 1 );
};

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
    int cabinets = 18;
    std::string cookingUtilities = "pan";
    int dirtyDishes = 8;
    int fridgeSpace = 48;
    int windows = 9;
    bool stoveToBeCleaned = true;

    void cook ( bool stoveUsed = true );
    void fridgeRestock ( int foodsize = 8 );
    void clean ( bool dishwasherRan = false );
};

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
    int mirrorSize = 8;
    int numSink = 2;
    int counterItems = 8;
    int timeSinceCleaned = 5;
    int toiletHeight = 17;
    int sinceShowerUsed = 0;
    int sinceToiletUsed = 3;
    bool changeSeat = false;
    bool readyForGuests = false;

    struct Shower
    {
        int headHeight = 64;
        bool inBath = false;
        std::string enclosure = "curtain";
        float waterTemp = 102;
        int showerlength = 12;
        bool cleanShower = false;

        float waterAmount ( float handlePosition = 0.5f  );
        void adjustWaterTemp (float coldPosition = 0.32f , float hotPosition = 0.69f);
        void drainClog ( bool clogged = false);
    };
    void useShower ( Shower Shower );
    void useToilet ( bool seatDownn = false );
    void clean ( bool bleachUsed = false );
};

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
    int sittingPlaces = 3;
    int TVsize = 42;
    int windows = 3;
    std::string wallColor = "red";
    int doors = 3;
    int piecesOfFurnature = 5;
    bool sataliteWatched = false;
    int timeSincePainted = 43;

    void useTV ( bool netflix = true );
    void paintRoom ( bool newcolor = false );
    void rearange ( int newfurnature = 1);
};

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
    Bedroom sarasRoom;
    Kitchen cookery;
    Bathroom lavatory;
    LivingRoom familyRoom;
    Garage storage;
    int rooms = 3;
    int value = 430300;
    int newWalls = 5;


    void addRoom ( int numNewRooms );
    void sellHouse ( int soldPrice = 804398 );
    void demolish ( int originalWallsRemaining = 1, int totalWalls = 4 );
};

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
    Exaqmple::main();
    std::cout << "good to go!" << std::endl;
}
