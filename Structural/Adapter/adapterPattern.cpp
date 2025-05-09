#include <cmath>
#include <iostream>

class RoundPeg {
  private:
    double m_radius;
  public:
    RoundPeg(double radius) : m_radius{ radius } {}
    virtual double getRadius() const { return m_radius; }  
};

class SquarePeg {
  private:
    double m_radius;
  public:
    SquarePeg(double radius) : m_radius{ radius } {}
    double getWidth() const { return m_radius; }  
};

class SquarePegAdapter : public RoundPeg {
  private:
    const SquarePeg& m_squarePeg;
  public:
    SquarePegAdapter(const SquarePeg& peg)
    : RoundPeg(0)
    , m_squarePeg(peg)
    {}

    double getRadius() const override {
      return (m_squarePeg.getWidth() * std::sqrt(2)) / 2.0;
    }

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
  
  SquarePeg squarePeg1(7.0);
  SquarePegAdapter adapter1(squarePeg1);
  
  // Even though squarePeg1 is larger than the hole's radius in its raw form,
  // after adapting we are checking if its effective radius fits inside the hole.
  std::cout << "Square peg with width 7.0 fits: " 
            << (hole.fits(adapter1) ? "Yes" : "No") << '\n';

  // Try with a smaller SquarePeg
  SquarePeg squarePeg2(5.0);
  SquarePegAdapter adapter2(squarePeg2);

  std::cout << "Square peg with width 5.0 fits: " 
            << (hole.fits(adapter2) ? "Yes" : "No") << '\n';
}
