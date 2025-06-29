#include <iostream>
#include <vector>
#include <string>

enum room_type {
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

struct Room {
    room_type roomName;
    float roomSquare = 0;
};

struct Floor {
    int numberRooms = 0;
    float ceilingHeight = 0;
    std::vector<Room> vecRooms;
};

enum facility_type {
    house,
    garage,
    barn,
    bathhouse
};

struct Facility {
    facility_type facilityName;
    float facilitySquare = 0;
    int numberFloors = 0;
    bool furnaceWithPipe = false;
    std::vector<Floor> vecFloors;
};

struct Region {
    int regionNumber = 0;
    int numberFacilities = 0;
    std::vector<Facility> vecFacilities;
};

int main() {
    std::cout << "\t\t*********************\n"
              << "\t\t* The village model *\n"
              << "\t\t*********************\n";

    float totalAreaVillage = 0;
    std::cout << "Input the total area of the village: ";
    std::cin >> totalAreaVillage;

    int numberRegions = 0;
    std::cout << "Input the number of regions in the village: ";
    std::cin >> numberRegions;
    //----------------Checking----------------------
    while (numberRegions <= 0) {
        std::cout << "Invalid data.\nInput again: ";
        std::cin >> numberRegions;
    }
    //----------------------------------------------
    std::vector<Region> vecRegions;

    int i = 0;
    while (i < numberRegions) {

        Region region;
        std::cout << std::endl;
        std::cout << "Input the number of the " << i + 1 << " region: ";
        std::cin >> region.regionNumber;
        //----------------Checking----------------------
        while (region.regionNumber <= 0) {
            std::cout << "Invalid data.\nInput again: ";
            std::cin >> region.regionNumber;
        }
        //----------------------------------------------
        std::cout << "Input the number of facilities on the region: ";
        std::cin >> region.numberFacilities;
        //----------------Checking----------------------
        while (region.numberFacilities < 0) {
            std::cout << "Invalid data.\nInput again: ";
            std::cin >> region.numberFacilities;
        }
        //----------------------------------------------
        if (region.numberFacilities == 0) {
            vecRegions.emplace_back(region);
        } else {
            std::string listFacilities;
            std::cout << "Select the types of facility: \n"
                      << "house - input \"0\" \n"
                      << "garage - input \"1\" \n"
                      << "barn - input \"2\" \n"
                      << "bathhouse - input \"3\" \n";
            std::cout << "Seiect: ";
            std::cin >> listFacilities;
            //-------------Checking-------------------------
            for (int i = 0; i < listFacilities.length(); ++i) {
                while (listFacilities[i] < '0' || listFacilities[i] > '3') {
                    std::cout << "Invalid data.\nInput again: ";
                    std::cin >> listFacilities;
                }
            }
            //----------------------------------------------

            for (int i = 0; i < listFacilities.length(); ++i) {

                Facility facility;
                if (listFacilities[i] == '0') {
                    facility.facilityName = facility_type::house;
                    std::cout << "Input the square of house: ";
                    std::cin >> facility.facilitySquare;
                    //-------------Checking-------------------------
                    while (facility.facilitySquare <= 0) {
                        std::cout << "Invalid data.\nInput again: ";
                        std::cin >> facility.facilitySquare;
                    }
                    //---------------------------------------------- 
                    std::cout << "Input the number of floors: ";
                    std::cin >> facility.numberFloors;
                    //-------------Checking-------------------------
                    while (facility.numberFloors < 1 || facility.numberFloors > 3) {
                        std::cout << "Invalid data.\nInput again: ";
                        std::cin >> facility.numberFloors;
                    }
                    //----------------------------------------------
                    for (int i = 0; i < facility.numberFloors; ++i) {

                        Floor floor;
                        std::cout << "Input the height of ceiling for " << i + 1 << " floor: ";
                        std::cin >> floor.ceilingHeight;
                        //-------------Checking-------------------------
                        while (floor.ceilingHeight < 1) {
                            std::cout << "Invalid data.\nInput again: ";
                            std::cin >> floor.ceilingHeight;
                        }
                        //----------------------------------------------
                        std::cout << "Input the number of rooms for " << i + 1 << " floor: ";
                        std::cin >> floor.numberRooms;
                        //-------------Checking-------------------------
                        while (floor.numberRooms < 2 || floor.numberRooms > 4) {
                            std::cout << "Invalid data.\nInput again: ";
                            std::cin >> floor.numberRooms;
                        }
                        //----------------------------------------------
                        std::string listRooms;
                        std::cout << "Select the types of room: \n"
                                  << "bedroom - input \"0\" \n"
                                  << "kitchen - input \"1\" \n"
                                  << "bathroom - input \"2\" \n"
                                  << "children - input \"3\" \n"
                                  << "living - input \"4\" \n";
                        std::cout << "Seiect: ";
                        std::cin >> listRooms;
                        
                        //---------------------Checking-----------------------------------
                        for (int i = 0; i < listRooms.length(); ++i) {
                            while (listRooms.length() != floor.numberRooms 
                                    || (listRooms[i] < '0' || listRooms[i] > '4')) {
                                std::cout << "Invalid data.\nInput again: ";
                                std::cin >> listRooms;                        
                            }
                        }
                        //----------------------------------------------------------------
                        
                        for (int i = 0; i < listRooms.length(); ++i) {

                            Room room;
                            if (listRooms[i] == '0') {
                                room.roomName = room_type::bedroom;
                                std::cout << "Input the square of bedroom: ";
                                std::cin >> room.roomSquare;
                                //-----------------------Checking-------------------------
                                while (room.roomSquare <= 0) {
                                    std::cout << "Invalid data.\nInput again: ";
                                    std::cin >> room.roomSquare;
                                }
                                //--------------------------------------------------------
                                floor.vecRooms.emplace_back(room);

                            } else if (listRooms[i] == '1') {
                                room.roomName = room_type::kitchen;
                                std::cout << "Input the square of kitchen: ";
                                std::cin >> room.roomSquare;
                                //-----------------------Checking-------------------------
                                while (room.roomSquare <= 0) {
                                    std::cout << "Invalid data.\nInput again: ";
                                    std::cin >> room.roomSquare;
                                }
                                //--------------------------------------------------------
                                floor.vecRooms.emplace_back(room);

                            } else if (listRooms[i] == '2') {
                                room.roomName = room_type::bathroom;
                                std::cout << "Input the square of bathroom: ";
                                std::cin >> room.roomSquare;
                                //-----------------------Checking-------------------------
                                while (room.roomSquare <= 0) {
                                    std::cout << "Invalid data.\nInput again: ";
                                    std::cin >> room.roomSquare;
                                }
                                //--------------------------------------------------------
                                floor.vecRooms.emplace_back(room);

                            } else if (listRooms[i] == '3') {
                                room.roomName = room_type::children;
                                std::cout << "Input the square of children: ";
                                std::cin >> room.roomSquare;
                                //-----------------------Checking-------------------------
                                while (room.roomSquare <= 0) {
                                    std::cout << "Invalid data.\nInput again: ";
                                    std::cin >> room.roomSquare;
                                }
                                //--------------------------------------------------------
                                floor.vecRooms.emplace_back(room);

                            } else {
                                room.roomName = room_type::living;
                                std::cout << "Input the square of living: ";
                                std::cin >> room.roomSquare;
                                //-----------------------Checking-------------------------
                                while (room.roomSquare <= 0) {
                                    std::cout << "Invalid data.\nInput again: ";
                                    std::cin >> room.roomSquare;
                                }
                                //--------------------------------------------------------
                                floor.vecRooms.emplace_back(room);
                            }
                        }
                        facility.vecFloors.emplace_back(floor);
                    }
                    
                    std::cout << "Does the house have a furnace with a pipe? \nYes - input \"1\", no - input \"0\": ";
                    std::cin >> facility.furnaceWithPipe;

                    region.vecFacilities.emplace_back(facility);

                } else if (listFacilities[i] == '1') {
                    facility.facilityName = facility_type::garage;
                    std::cout << "Input the square of garage: ";
                    std::cin >> facility.facilitySquare;
                //-------------Checking-------------------------
                while (facility.facilitySquare <= 0) {
                    std::cout << "Invalid data.\nInput again: ";
                    std::cin >> facility.facilitySquare;
                }
                //---------------------------------------------- 
                region.vecFacilities.emplace_back(facility);

                } else if (listFacilities[i] == '2') {
                    facility.facilityName = facility_type::barn;
                    std::cout << "Input the square of barn: ";
                    std::cin >> facility.facilitySquare;
                    //-------------Checking-------------------------
                    while (facility.facilitySquare <= 0) {
                        std::cout << "Invalid data.\nInput again: ";
                        std::cin >> facility.facilitySquare;
                    }
                    //---------------------------------------------- 
                    region.vecFacilities.emplace_back(facility);

                } else {
                    facility.facilityName = facility_type::bathhouse;
                    std::cout << "Input the square of bathhouse: ";
                    std::cin >> facility.facilitySquare;
                    //-------------Checking-------------------------
                    while (facility.facilitySquare <= 0) {
                        std::cout << "Invalid data.\nInput again: ";
                        std::cin >> facility.facilitySquare;
                    }
                    //---------------------------------------------- 
                    std::cout << "Does the bathhouse have a furnace with a pipe? \nYes - input \"1\", no - input \"0\": ";
                    std::cin >> facility.furnaceWithPipe;
                    
                    region.vecFacilities.emplace_back(facility);
                }
            }
            vecRegions.emplace_back(region);
        }
        i++;
    }

    float totalAreaFacilities = 0;

    std::cout << std::endl;
    std::cout << "The village consists of " << vecRegions.size() << " regions.\n";
    for (int i = 0; i < vecRegions.size(); ++i) {
        std::cout << std::endl;
        std::cout << "Region number: " << vecRegions[i].regionNumber << std::endl;
        std::cout << "Number facilities " << vecRegions[i].numberFacilities << ":" << std::endl;

        for (int q = 0; q < vecRegions[i].vecFacilities.size(); ++q) {
            if (vecRegions[i].vecFacilities[q].facilityName == facility_type::house) {
                std::cout << "- house\n";
            } else if (vecRegions[i].vecFacilities[q].facilityName == facility_type::garage) {
                std::cout << "- garage\n";
            } else if (vecRegions[i].vecFacilities[q].facilityName == facility_type::barn) {
                std::cout << "- barn\n";
            } else if (vecRegions[i].vecFacilities[q].facilityName == facility_type::bathhouse) {
                std::cout << "- bathhouse\n";
            }
        }

        if (vecRegions[i].numberFacilities > 0) {
            for (int j = 0; j < vecRegions[i].vecFacilities.size(); ++j) {
                if (vecRegions[i].vecFacilities[j].facilityName == facility_type::house) {
                    std::cout << "The square of the house: " << vecRegions[i].vecFacilities[j].facilitySquare << std::endl;
                    std::cout << "The number of floors in the house: " << vecRegions[i].vecFacilities[j].numberFloors << std::endl;

                    for (int k = 0; k < vecRegions[i].vecFacilities[j].vecFloors.size(); ++k) {
                        std::cout << "Ceiling height of the " << k + 1 << " floor: " << vecRegions[i].vecFacilities[j].vecFloors[k].ceilingHeight << std::endl;
                        std::cout << "Number of rooms on the " << k + 1 << " floor: " << vecRegions[i].vecFacilities[j].vecFloors[k].numberRooms << std::endl;

                        for (int w = 0; w < vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms.size(); ++w) {
                            if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[w].roomName == room_type::bedroom) {
                                std::cout << "- bedroom\n";
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[w].roomName == room_type::kitchen) {
                                std::cout << "- kitchen\n";
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[w].roomName == room_type::bathroom) {
                                std::cout << "- bathroom\n";
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[w].roomName == room_type::children) {
                                std::cout << "- children\n";
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[w].roomName == room_type::living) {
                                std::cout << "- living\n";
                            }
                        } 

                        for (int m = 0; m < vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms.size(); ++m) {
                            if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomName == room_type::bedroom) {
                                std::cout << "The square of the bedroom: " << vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomSquare << std::endl;
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomName == room_type::kitchen) {
                                std::cout << "The square of the kitchen: " << vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomSquare << std::endl;
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomName == room_type::bathroom) {
                                std::cout << "The square of the bathroom: " << vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomSquare << std::endl;
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomName == room_type::children) {
                                std::cout << "The square of the children: " << vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomSquare << std::endl;
                            } else if (vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomName == room_type::living) {
                                std::cout << "The square of the living: " << vecRegions[i].vecFacilities[j].vecFloors[k].vecRooms[m].roomSquare << std::endl;
                            }
                        }
                    }
                    std::cout << "Furnace with a pipe: " << std::boolalpha << vecRegions[i].vecFacilities[j].furnaceWithPipe <<std::endl;

                    totalAreaFacilities += vecRegions[i].vecFacilities[j].facilitySquare;
                
                } else if (vecRegions[i].vecFacilities[j].facilityName == facility_type::garage) {
                    std::cout << "The square of the garage: " << vecRegions[i].vecFacilities[j].facilitySquare << std::endl;
                    totalAreaFacilities += vecRegions[i].vecFacilities[j].facilitySquare;
                } else if (vecRegions[i].vecFacilities[j].facilityName == facility_type::barn) {
                    std::cout << "The square of the barn: " << vecRegions[i].vecFacilities[j].facilitySquare << std::endl;
                    totalAreaFacilities += vecRegions[i].vecFacilities[j].facilitySquare;
                } else if (vecRegions[i].vecFacilities[j].facilityName == facility_type::bathhouse) {
                    std::cout << "The square of the bathhouse: " << vecRegions[i].vecFacilities[j].facilitySquare << std::endl;
                    std::cout << "Furnace with a pipe: " << std::boolalpha << vecRegions[i].vecFacilities[j].furnaceWithPipe <<std::endl << std::endl;
                    totalAreaFacilities += vecRegions[i].vecFacilities[j].facilitySquare;
                }
            }
        } else {
            std::cout << "There are no facilities on the region.\n";
        }
    }
    std::cout << std::endl;
    std::cout << "The total area of the village: " << totalAreaVillage << std::endl;   
    std::cout << "Total area of facilities in the village: " << totalAreaFacilities << std::endl; 

    float percentageVillageOfFacilities = totalAreaFacilities / totalAreaVillage * 100;
    std::cout << "Percentage of village land occupied by facilities: " << percentageVillageOfFacilities << " %" << std::endl;
}