#include <iostream>

class RoundPeg {
  private:
    double m_radius;
  public:
    RoundPeg(double radius) : m_radius{ radius } {}
    double getRadius() const { return m_radius; }  
};

class SquarePeg {
  private:
    double m_radius;
  public:
    SquarePeg(double radius) : m_radius{ radius } {}
    double getWidth() const { return m_radius; }  
};

class RoundHole {
  private:
    double m_radius;
  public:
    RoundHole(double radius) : m_radius{ radius } {}

    bool fits(const RoundPeg& peg) const {
      return peg.getRadius() <= m_radius;
    }
};

int main() {
  RoundHole hole(5.0);
  RoundPeg roundPeg(5.0);

  std::cout << "Round peg fits: " << (hole.fits(roundPeg) ? "Yes" :  "No") << '\n';
  
  SquarePeg squarePeg(5.0);
  
  // This would error out because RoundHole is expecting a square peg
  // std::cout << "Square peg fits: " << (hole.fits(squarePeg) ? "Yes" : "No") << '\n';
}
