#include "Radio.h"


Radio::Radio() {

	volume = 3;
	station = MIN_STATION;
}

Radio::Radio(const Radio& R) {

	volume = R.volume;
	station = R.station;

}

unsigned int Radio::getStation() const {
	return station;
}

unsigned int Radio::getVolume() const {
	return volume;
}

void Radio::setVolume(unsigned int const& volume) {

	if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) this->volume = volume;

}

void Radio::setStation(unsigned int const& station) {

	if (station >= MIN_STATION && station <= MAX_STATION) this->station = station;

}

void Radio::incVolume() {

	setVolume(volume + 1);

}

void Radio::decVolume() {

	setVolume(volume - 1);

}

void Radio::nextStation() {

	setStation(station + 1);

}

void Radio::previousStation() {

	setStation(station - 1);

}