#include <iostream>
#include <vector>
using namespace std;

class State {
  public:
    class Transition {
      public:
        double reward;
        int nextState;

        Transition(double reward, int nextState) : reward(reward), nextState(nextState) {}
    };

    vector<Transition> transitions;

    State(double r1 = 0.0, int ns1 = 0, double r2 = 0.0, int ns2 = 0, double r3 = 0.0, int ns3 = 0, double r4 = 0.0, int ns4 = 0) {
      transitions.push_back(Transition(r1, ns1));
      transitions.push_back(Transition(r2, ns2));
      transitions.push_back(Transition(r3, ns3));
      transitions.push_back(Transition(r4, ns4));
    }
};

int main() {
  int iterations;
  cin >> iterations;

  vector<State> states(25);
  states[0] = State(-1, 0, 0, 5, -1, 0, 0, 1);
  states[1] = State(10, 21, 10, 21, 10, 21, 10, 21);
  states[2] = State(-1, 2, 0, 7, 0, 1, 0, 3);
  states[3] = State(5, 13, 5, 13, 5, 13, 5, 13);
  states[4] = State(-1, 4, 0, 9, 0, 3, -1, 4);
  states[5] = State(0, 0, 0, 10, -1, 5, 0, 6);
  states[6] = State(0, 1, 0, 11, 0, 5, 0, 7);
  states[7] = State(0, 2, 0, 12, 0, 6, 0, 8);
  states[8] = State(0, 3, 0, 13, 0, 7, 0, 9);
  states[9] = State(0, 4, 0, 14, 0, 8, -1, 9);
  states[10] = State(0, 5, 0, 15, -1, 10, 0, 11);
  states[11] = State(0, 6, 0, 16, 0, 10, 0, 12);
  states[12] = State(0, 7, 0, 17, 0, 11, 0, 13);
  states[13] = State(0, 8, 0, 18, 0, 12, 0, 14);
  states[14] = State(0, 9, 0, 19, 0, 13, -1, 14);
  states[15] = State(0, 10, 0, 20, -1, 15, 0, 16);
  states[16] = State(0, 11, 0, 21, 0, 15, 0, 17);
  states[17] = State(0, 12, 0, 22, 0, 16, 0, 18);
  states[18] = State(0, 13, 0, 23, 0, 17, 0, 19);
  states[19] = State(0, 14, 0, 24, 0, 18, -1, 19);
  states[20] = State(0, 15, -1, 20, -1, 20, 0, 21);
  states[21] = State(0, 16, -1, 21, 0, 20, 0, 22);
  states[22] = State(0, 17, -1, 22, 0, 21, 0, 23);
  states[23] = State(0, 18, -1, 23, 0, 22, 0, 24);
  states[24] = State(0, 19, -1, 24, 0, 23, -1, 24);

  vector<double> oldValues(25);
  vector<double> newValues(25);
  for (int i = 0; i < 25; i++) {
    oldValues[i] = 0;
    newValues[i] = 0;
  }

  for (int i = 0; i < iterations; i++) {
    for (int j = 0; j < 25; j++) {
      newValues[j] = 0.0;

      for (int k = 0; k < 4; k++) {
        newValues[j] += 0.25 * (states[j].transitions[k].reward + 0.9 * oldValues[states[j].transitions[k].nextState]);
      }
    }

    for (int j = 0; j < 25; j++) {
      oldValues[j] = newValues[j];
    }
  }

  for (int i = 0; i < 25; i++) {
    cout << newValues[i] << " ";
    if ((i + 1) % 5 == 0) {
      cout << endl;
    }
  }

  return 0;
}
