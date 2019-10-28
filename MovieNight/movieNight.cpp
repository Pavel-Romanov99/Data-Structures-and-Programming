#include <iostream>
#include <queue>
using namespace std;

class MovieNight
{
private:
	//times in seconds
	int total_time = 1800;
	int popcorn_time = 90;
	int ticket_time = 30;
	int enter_time = 105;
	int counter = 0;
	int popcorn_counter = 0;

	//ticket queue
	queue<int> ticket;

	//popcorn queue
	queue<int> popcorn;

	//enter queue
	queue<int> enter;
public:
	bool coinToss() {
		// 70% chance of a person going to the popcorn
		bool TrueFalse = (rand() % 100) < 70;
		if (TrueFalse == true) {
			return true;
		}
		return false;
	}

	void Simulation() {

		while (total_time != 0)
		{


			//every 120 seconds a random number of people are pushed to the ticket queue
			if (this->total_time % 120 == 0) {
				//random number of people
				int number_people;
				cin >> number_people;

				for (int i = 0; i < number_people; i++)
				{
					int person;
					cin >> person;
					ticket.push(person);
				}
			}

			else if (!ticket.empty()) {
				if (this->total_time % ticket_time == 0 && coinToss()) {
					// the customer goes from tickets to popcorn
					popcorn.push(ticket.front());
					ticket.pop();
				}
				else {
					//the customer goes directly to enter
					enter.push(ticket.front());
					ticket.pop();
				}
			}

			//if there are people on the popcorn queue they go to enter every 90 seconds
			else if (!popcorn.empty() && this->total_time % popcorn_time == 0) {
				//they leave the popcorn queue and enter to the enter queue
				enter.push(popcorn.front());
				popcorn.pop();
			}

			//if the enter queue isn't empty 1 person enters the movie every
			else if (!enter.empty() && total_time % enter_time == 0) {
				//a person enters to watch the movie
				enter.pop();
			}

			//the ticket seller closes after 900 seconds and all the people are left outside
			else if (!ticket.empty() && total_time % 900 == 0) {
				while (!ticket.empty()) {
					this->counter++;
					ticket.pop();
				}
			}

			//when the timer is 0 we add all the people in the enter queue to the leftOutside
			else if (total_time == 0) {
				while (!enter.empty()) {
					this->counter++;
					enter.pop();
				}

				while (!popcorn.empty())
				{
					popcorn_counter++;
					popcorn.pop();
				}
			}
			total_time--;
		}
	}

	int leftOutside() {
		return counter;
	}

	int Waiting_for_Popcorn()
	{
		return popcorn_counter;
	}
};

int main()
{
	MovieNight a;
	a.Simulation();
	cout << "People left outside - " << a.leftOutside() << endl;
	cout << "Poeple waiting for popcorn - " << a.Waiting_for_Popcorn() << endl;
}
