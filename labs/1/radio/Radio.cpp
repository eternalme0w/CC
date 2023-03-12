#include "Radio.h"


Radio::Radio() {

	volume = 3;
	station = MIN_STATION;
}

Radio::Radio(const Radio& R) {

	volume = R.volume;
	station = R.station;
}

Radio& Radio::operator=(const Radio& R) {

	volume = R.volume;
	station = R.station;

	return *this;
}

Radio& Radio::operator++() {

	nextStation();
	return *this;
}

Radio Radio::operator++(int) {

	Radio copy = *this;
	nextStation();
	return copy;
}

Radio &Radio::operator--()
{

	previousStation();
	return *this;
}

Radio Radio::operator--(int)
{

	Radio copy = *this;
	previousStation();
	return copy;
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

	if (station == MAX_STATION) setStation(MIN_STATION);
	else setStation(station + 1);
	
}

void Radio::previousStation() {
	
	if (station == MIN_STATION) setStation(MAX_STATION);
	else setStation(station - 1);
}