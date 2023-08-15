#pragma once

#include <string>
using namespace std;

template <class T>
class State
{
public:
    State(const T &state, double cost = 0, State<T> *cameFrom = nullptr)
        : m_state(state), m_cost(cost), m_cameFrom(cameFrom) {}
    ~State() {}

public:
    // bool operator==(State &s) { return m_state.compare(s.m_state) == 0; }
    // bool operator==(const State &s) const { return m_state == s.m_state; }
    // bool operator==(const State<T> &s) const { return m_state == s.m_state; }
    // bool operator==(const State &other) const { return m_state == other.m_state; }
    //    bool operator==(const State& s) { return m_state == s.m_state; }
    // bool operator==(const State &other) const { return m_state == other.m_state; }
    // bool operator==(const State<T> &other) const { return m_state == other.m_state; }
    //  bool operator==(const State& s) const { return m_state == s.m_state; }
    T &getState() { return m_state; }
    const T &getState() const { return m_state; }
    void setState(T &state) { m_state = state; }
    double getCost() { return m_cost; }
    double getCost() const { return m_cost; }
    void setCost(double cost) { m_cost = cost; }
    void setCameFrom(State<T> *state) { m_cameFrom = state; }
    void setCameFrom(const State<T> *state) { m_cameFrom = state; }
    State<T> *getCameFrom() { return m_cameFrom; }
    const State<T> *getCameFrom() const { return m_cameFrom; };
    bool isVisited() const { return m_visited; }
    void setVisited(bool visited) { m_visited = visited; }
    bool operator==(const State<T> &s) const
    {
        return m_state == s.m_state; // Assuming m_state is a member of your State class
    }
    bool operator<(const State<T> &other) const
    {
        // Compare based on the m_value member variable
        return m_state < other.m_state;
    }
       void printState() const
    {
        std::cout << "State Information:" << std::endl;
        // Print relevant information about the state
        std::cout << "Maze Data:" << std::endl;
        m_state.display();
        std::cout << "Cost: " << m_cost << std::endl;
        // ... Print other attributes if needed ...
    }

private:
    T m_state;
    double m_cost;
    const State<T> *m_cameFrom;
    bool m_visited;
};
