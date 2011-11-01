#include "readers.h"

// Track Reader
namespace CS262 {
LinkedList<tile> trackReader() {
	ifstream inFileTracks( "tracks.txt" );
		if( !inFileTrack ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
	}
	
	string tileType;
	int length;
	double accMulti;
	LinkedList<tile> Track;
	tile intile;
	Boost inBoost;
	Turn inTurn;
	
	inFileTrack >> length;
	for(int i = 0; i < length; i++) {
		inFileTrack >> tileType;
		if(tileType == "boost") {
			inFileTrack >> accMulti;
			inBoost.set_acc_multi(accMulti);
			inBoost.set_num(i);
			Track.insertAtTail(inBoost);
		} else if(tileType == "turn") {
			inFileTrack >> maxspeed;
			inTurn.set_num(i);
			inTurn.set_max_speed_allowed(maxspeed);
			Track.insertAtTail(inTurn);
		} else {
			intile.set_num(i);
			Track.insertAtTail(intile);
		}
	}

	inFileTracks.close();

	return Track;
}
}