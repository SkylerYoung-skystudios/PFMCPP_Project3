/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};

struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()





struct Shoe
{
    std::string brand { "Nike" };
    double size { 0 };
    std::string color { "white" };
    std::string condition { "good" };
    std::string securingMethod { "velcro" };
    double percentOfSoleLeft = 100;
    Shoe();

    void putOn ( std::string firstShoe = "R", bool leftFirst = true);
    void takeOff ( std::string firstShoe = "R", bool leftFirst = true );
    void throwAway ( bool donate = false );
    void wearDown(int timesWorn)
    {
        for (int i = 0; i <= timesWorn; i += 1)
        {
            percentOfSoleLeft -= 0.2;
        }

        std::cout << "Sole percent left " << percentOfSoleLeft << std::endl;
    }
};

Shoe::Shoe(){}

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
    int volumeLevel;
    double vibratoAmount;
    std::string model;
    std::string condition;
    int numKeys;
    int output = 23;
    bool on;
    Wurlitzer();

    void changeVolume ( int knobPosition );
    void play ( int note = 23 );
    void power ( bool switchPosition = true );
    void printCondition()
    {
       std::cout << "This Wutlizer is in " << condition << " condition\n"; 
    }
    int swellVolume(int amount, int time)
    {
        int swell = 0;
        for (int i = 0; i <= time ; i += 1)
        {
            swell += 20;
            if (swell >= amount)
            {
                std::cout << "Swell finished" << std::endl;
                return swell;
            }
        }
        return swell;
    }
};

Wurlitzer::Wurlitzer() :
volumeLevel ( 6 ),
vibratoAmount ( .5 ),
model ( "200a" ),
condition ( "good" ),
numKeys ( 49 ),
output ( 23 ),
on ( false )
{

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
    int numStrings = 4;
    std::string pickup = "precision";
    std::string brand = "fender";
    std::string model = "precision";
    int yearMade = 1974;
    int output = 23;
    int cost = 1544;
    int timeSinceRestrung = 13;
    bool timeToRestring = false;
    ElectricBass();

    void play ( int note =  18 );
    void sold ( int price = 1200 );
    void restring ( bool restring = true );
    void checkStrings (int timesPlayed)
    {
        for (int i = 0; i <= timesPlayed; i += 1)
        {
            timeSinceRestrung += 1; 
        }

        if (timeSinceRestrung > 60)
        {
            timeToRestring = true;
            std::cout << "Time to change strings!" << std::endl;
        }
        else
        {
            std::cout << "Strings are still good!" << std::endl;
        }
    } 
};

ElectricBass::ElectricBass(){}

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
    int buildingsToBeRepaired = 10000;
    bool repairsFinished = false;
    int capital;

    void vote (int party1Votes = 13876, int party2Votes = 43786 );
    void naturalDisaster ( int percentOfPropertiesDamaged = 47 );
    void buildTransportation ( int cost = 2433244 );
    void fixBuildings()
    {
        int time = 0;
        while (buildingsToBeRepaired > 0)
        {
            buildingsToBeRepaired -= 2540;
            time += 1;
        }
        std::cout << "Repairs finished in " << time << " years" << std::endl;
    }
};

City::City() : population { 4649231 }, size { 34.65f }, GDP { 65569340958.98 }, averageAge { 43 }, country { "New Zeland" }, party1InCharge { true }, buildingsToBeRepaired { 100000 }, capital { 14414414 } {}

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
    Bedroom();

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
        Bed();

        void makeBed ( bool newSheets = true);
        void sleepInBed (std::string sleeper = "jeff");
        void newMatress ( std::string brand = "tempurpedic");
        void printLastInBed()
        {
            std::cout << "Last in bed was " << lastInBed << "\n";
        }
    };
    void sleepIn ( int timeAwake = 843, int timeAsleep = 98);
    void clean ( bool vacumed = true );
    void rearange ( int newFurnature = 1 );
};

Bedroom::Bed::Bed(){}

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
    int cabinets = 18;
    std::string cookingUtilities = "pan";
    int dirtyDishes = 8;
    int fridgeSpace = 48;
    int windows = 9;
    bool stoveToBeCleaned = true;
    Kitchen();

    void cook ( bool stoveUsed = true );
    void fridgeRestock ( int foodsize = 8 );
    void clean ( bool dishwasherRan = false );
};

Kitchen::Kitchen(){}

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
    Bathroom();

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

Bathroom::Bathroom(){}

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
    int sittingPlaces = 3;
    int TVsize = 42;
    int windows = 3;
    std::string wallColor = "red";
    int doors = 3;
    int piecesOfFurnature = 5;
    bool sataliteWatched = false;
    int timeSincePainted = 43;
    LivingRoom();

    void useTV ( bool netflix = true );
    void paintRoom ( bool newcolor = false );
    void rearange ( int newfurnature = 1);
    void printOcupants()
    {
        std::cout << "This living room fits " << sittingPlaces << " people\n";
    }

};

LivingRoom::LivingRoom(){}

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
    Garage();

    void parkCar ( bool spotAOpen = true, bool spotBOpen = true, bool spotCOpen = true );
    void doorOpen ( bool fromCar = true );
    void altUsage ( std::string garageUsage = "art studio");

};

Garage::Garage(){}

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

House::House() :
    rooms { 3 },
    value { 430300 },
    newWalls { 5 }
{

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
    City losAngeles, seattle;
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

    tan.printCondition();

    myBed.printLastInBed();

    frontRoom.printOcupants();

    blazer.wearDown(47);

    precision.checkStrings(84);

    seattle.fixBuildings();

    red.output = red.swellVolume(60, 5);
}
