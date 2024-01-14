//============================================================================
// Name        : Battleship_Game.cpp
// Author      : Azaz Hassan Khan
// Version     : V1.0
// Copyright   : Your copyright notice
// Description : German Battle Ship Game
//============================================================================
#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Shot.h"

/* Check Validation of functions*/
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}
/* Printing Ships*/
void GetShips(vector<Ship> TempShip, string text)
{
	cout<<text<<endl;

	for (auto ship:TempShip )
	{
		cout<<"{"<<ship.getBowRow() + to_string(ship.getBowColumn())<<","
		<<ship.getSternRow() + to_string(ship.getSternColumn())<<"}"<<endl;
	}
}

int main() {

///*   ---------------  Test(GridPosition Class)  ----------------------*/
//
//	// Test GridPosition constructor
//	assertTrue(GridPosition{'A', 1}.isValid(), "A1 not considered valid");
//	assertTrue(!GridPosition{'A', -1}.isValid(), "A-1 considered valid");
//	assertTrue(!GridPosition{'@', 1}.isValid(), "@1 considered valid");
//	GridPosition fromRowCol{'A', 1};
//	GridPosition fromString{"A1"};
//	assertTrue(fromRowCol.getRow() == fromString.getRow()
//			&& fromRowCol.getColumn() == fromString.getColumn(),
//			"different constructors return different objects");
//
//    // Test comparison
//    assertTrue(!(GridPosition{"A1"} < GridPosition{"A1"}),
//            "Same positions considered different by '<'");
//    assertTrue(GridPosition{"A1"} < GridPosition{"B1"},
//            "Position with bigger row not considered greater");
//    assertTrue(GridPosition{"A1"} < GridPosition{"A2"},
//            "Position with bigger column not considered greater");
//    assertTrue(GridPosition{"C21"} == GridPosition{"C21"},
//            "Equal positions not considered equal.");
//
//    // Test getters and cast to string
//	GridPosition pos1 = GridPosition{'B', 13};
//	assertTrue(pos1.getRow() == 'B',
//			"GridPosition::GridPosition doesn't set row properly.");
//	assertTrue(pos1.getColumn() == 13,
//			"GridPosition::GridPosition doesn't set column properly.");
//	assertTrue((string)pos1 == "B13", "Conversion to string fails.");
//
///* ------------------------ Test(Ship Class) ---------------------------------*/
//
//    // Test Ship Constructor
//    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"C3"}}.isValid(),
//            "Can create non-aligned ship.");
//    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B2"}}.isValid(),
//            "Can create ship of size 1.");
//    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B7"}}.isValid(),
//            "Can create ship of size 6.");
//    assertTrue(!Ship{GridPosition{"B2"}, GridPosition{"B3"}}.isValid(),
//            "Can not create ship of size 2.");
//
//    // Length
//     assertTrue(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.length() == 3,
//             "Length is not 3");
//     assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.length() == 4,
//             "Length is not 4");
//
//     // Occupied area
//     assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.occupiedArea()
//               == set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
//               GridPosition{"D2"}, GridPosition{"E2"}},
//             "Occupied area not correct");
//
//     assertTrue(Ship{GridPosition{"B1"}, GridPosition{"B5"}}.occupiedArea()
//               == set<GridPosition>{GridPosition{"B1"}, GridPosition{"B2"},
//               GridPosition{"B3"}, GridPosition{"B4"}, GridPosition{"B5"}},
//               "Occupied area not correct");
//     // Blocked area
//     assertTrue(Ship{GridPosition{"B2"}, GridPosition{"E2"}}.blockedArea()
//               == set<GridPosition>{GridPosition{"B2"}, GridPosition{"C2"},
//               GridPosition{"D2"}, GridPosition{"E2"},GridPosition{"A1"},
//			   GridPosition{"A2"},GridPosition{"A3"},GridPosition{"B1"},
//			   GridPosition{"B3"},GridPosition{"C1"},GridPosition{"C3"},
//			   GridPosition{"D1"},GridPosition{"D3"},GridPosition{"E1"},
//			   GridPosition{"E3"},GridPosition{"F1"},GridPosition{"F2"},
//			   GridPosition{"F3"}},   "Occupied area not correct");
//
//
//     assertTrue(Ship{GridPosition{"B1"}, GridPosition{"B5"}}.blockedArea()
//               == set<GridPosition>{GridPosition{"B1"}, GridPosition{"B2"},
//               GridPosition{"B3"}, GridPosition{"B4"}, GridPosition{"B5"},
//			   GridPosition{"A1"}, GridPosition{"B1"}, GridPosition{"C1"},
//			   GridPosition{"A2"}, GridPosition{"C2"}, GridPosition{"A3"},
//			   GridPosition{"C3"}, GridPosition{"A4"}, GridPosition{"C4"},
//			   GridPosition{"A5"}, GridPosition{"C5"}, GridPosition{"A6"},
//			   GridPosition{"B6"}, GridPosition{"C6"}},
//               "Occupied area not correct");
//
//     // Test getters functions for bow and stern
// 	Ship ship1 = Ship{GridPosition{"B1"}, GridPosition{"B5"}};
// 	assertTrue(ship1.getBow() == GridPosition{"B1"},
// 			"Ship doesn't set Bow properly.");
// 	assertTrue(ship1.getStern() == GridPosition{"B5"},
// 			"Ship doesn't set Stern properly.");

///* ------------------------ Test(OwnGrid Class) ------------------------------*/
//
//    // Test Grid Constructor
// 	assertTrue(OwnGrid{'A',1}.isValid(),"Grid construction is not valid");
//    assertTrue(!OwnGrid{'A',0}.isValid(),"Grid construction is  valid");
//    assertTrue(!OwnGrid{'a',1}.isValid(),"Grid construction is  valid");
//
//	//Checking and testing Placement Function
//    OwnGrid owngrid;
//	assertTrue(owngrid.placeShip(Ship{{"B2"},{"B6"}}) == 1,  //size 5
//			 "Ship placement is Unsuccesesfull");
//	assertTrue(!owngrid.placeShip(Ship{{"F6"},{"F10"}}) == 1,  //size 5
//			 "Shipplacement is Succesesfull");
//	assertTrue(!owngrid.placeShip(Ship{{"B2"},{"D2"}}) == 1,  //Intersection
//			 "Ship placement is Succesesfull");
//	assertTrue(owngrid.placeShip(Ship{{"D2"},{"D3"}}) == 1,  //size 2
//			 "Shipplacement is Unsuccesesfull");
//	assertTrue(owngrid.placeShip(Ship{{"F6"},{"F9"}}) == 1,  //size 4
//			 "Shipplacement is Unsuccesesfull");
//


/*   ---------------  Test1(Placing Ships on OwnGrid)  ----------------------*/

//	  cout<<"TEST 1"<<endl;
//	  Board board('J',10);
//	  board.getOwnGrid().placeShip(Ship{{"B2"},{"B4"}});  // type 3 ship
//	  board.getOwnGrid().placeShip(Ship{{"D4"},{"G4"}});  // type 4 ship
//	  board.getOwnGrid().placeShip(Ship{{"F6"},{"F9"}});  // type 4 ship
//	  ConsoleView console(&board);
//	  console.print();
//
//	  // Test getShips functionality
//	  GetShips(board.getOwnGrid().getShips(),"Ship Placements");

///*   ---------------  Test2(Taking Shots on OwnGrid)------------------------*/
//
//	  cout<<"TEST 2"<<endl;
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 3});
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 4});
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 5});
//
//	  console.print();
//	  GetShips(board.getOwnGrid().getShips(),"Ship Placements");


///*   -----------Test3(Taking Shots on to sunk all ships OwnGrid)-----------*/
//
//	  cout<<"TEST 3"<<endl;
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 2});
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 3});
//	  board.getOwnGrid().takeBlow(GridPosition{'B', 4});
//
//	  board.getOwnGrid().takeBlow(GridPosition{'D', 4});
//	  board.getOwnGrid().takeBlow(GridPosition{'E', 4});
//	  board.getOwnGrid().takeBlow(GridPosition{'F', 4});
//	  board.getOwnGrid().takeBlow(GridPosition{'G', 4});
//
//	  board.getOwnGrid().takeBlow(GridPosition{'F', 6});
//	  board.getOwnGrid().takeBlow(GridPosition{'F', 7});
//	  board.getOwnGrid().takeBlow(GridPosition{'F', 8});
//	  board.getOwnGrid().takeBlow(GridPosition{'F', 9});
//
//	  console.print();
//
//	  GetShips(board.getOwnGrid().getShips(),"Ship Placements");


/*   -----------Test4(Taking Shots on to OpponentsGrid)-----------*/

//	  cout<<"TEST 4"<<endl;
//
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'C', 2}}, NONE);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'C', 3}}, HIT);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'C', 4}}, HIT);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'C', 5}}, SUNKEN);
//
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'F', 5}}, NONE);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'G', 5}}, HIT);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'G', 6}}, HIT);
//	  board.getOpponentGrid().shotResult(Shot{GridPosition{'I', 5}}, NONE);
//
//	  console.print();
//	  GetShips(board.getOpponentGrid().getSunkenShips(),"Sunken Ships");

//	// Testing Shot Class
//	assertTrue((Shot{GridPosition{'A', 1}}).isValid(), "Shot not considered valid");
//	assertTrue(!(Shot{GridPosition{'a', 1}}).isValid(), "Shot considered valid");
//

	return 0;
}
