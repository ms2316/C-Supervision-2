#include <iostream>
#include <bitset>

using namespace std;


struct Error {
	int errorcode;
	Error(int i):errorcode(i) {}
};

class BitQueue {

    int valid_bits; // the number of valid bits held in queue
    int queue;      // least significant bit is most recent bit added

public:

    BitQueue(): valid_bits(0), queue(0) {}
    void push(int val, int bsize);
    int pop(int bsize);
    int size();

};

int BitQueue::size() {
	return valid_bits;
}

void BitQueue::push(int val, int bsize) {
	if (bsize + valid_bits > 32)
		throw Error(1); 
	valid_bits+= bsize;

	unsigned int tmp = -1;
	tmp >>= (32-bsize);

	queue <<= bsize;
	queue += (tmp&val);
}

int BitQueue::pop(int bsize) {
	if (valid_bits < bsize)
		throw Error(0);

	unsigned int tmp = -1;
	tmp >>= (32-valid_bits);
	int ans = ((queue&tmp) >> (valid_bits-bsize));

	valid_bits-=bsize;
	return ans;
}


void send(char ch) {
	cout << bitset<8>(ch) << endl;
}

void sendmsg(const char* msg) {
	BitQueue q;
	while ( (*msg) != '\0' ) {

		switch (*msg) {
			case 'a': q.push(0,1); break;
			case 'b': q.push(2,2); break;
			case 'c': q.push(12,4); break;
			case 'd': q.push(13,4); break;
		}

		if (q.size() >= 8)	
			send(q.pop(8));
		msg++;
	}

	q.push(7,3);

	if (q.size() > 8) {
		send(q.pop(8));
	}

	q.push(0,8-q.size());
	send(q.pop(8));
}

int main() {
	sendmsg("abcd\0");
	cout << endl;
	sendmsg("abcdba\0");
}