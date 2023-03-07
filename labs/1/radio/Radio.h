#pragma once

class Radio {

	const unsigned int MIN_VOLUME = 0;
	const unsigned int MAX_VOLUME = 10;
	unsigned int volume;
	
	const unsigned int MIN_STATION = 1;
	const unsigned int MAX_STATION = 10;
	unsigned int station;

public:

	Radio();
	Radio(const Radio&);

	unsigned int getStation() const;
	unsigned int getVolume() const;

	void setVolume(unsigned int const& volume);
	void setStation(unsigned int const& station);

	void incVolume();
	void decVolume();

	void nextStation();
	void previousStation();

};