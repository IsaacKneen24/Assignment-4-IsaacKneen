/*
Purpose: Test driver for Particle class functionality.
Student ID: 10821713
Date: 07/03/2025
Description: Demonstrates assignment requirements including particle creation, 
             four-momentum operations, move/copy semantics, and vector interactions. 
             Tests include: sum of electron momenta, muon dot product, copy/move 
             operations, and memory address verification.
*/

#include "Particle.h"
#include <vector>
#include <iostream>

int main() 
{
  // ===== ASSIGNMENT PART 3 REQUIREMENTS =====

  // 1. Create test particles
  std::cout << "\n=== Creating 2 electrons, 2 muons, 2 taus ===\n";
  Particle electron1("electron", 0.511, 0.1, 0.2, 0.3);
  Particle electron2("electron", 0.511, 0.4, 0.5, 0.6);
  Particle muon1("muon", 105.7, 1.1, 1.2, 1.3);
  Particle muon2("muon", 105.7, 2.1, 2.2, 2.3);
  Particle tau1("tau", 1777, 3.1, 3.2, 3.3);
  Particle tau2("tau", 1777, 4.1, 4.2, 4.3);

  // 2. Sum four-momenta of electrons
  std::cout << "\n=== Summing four-momenta of electrons ===\n";
  Particle combined_e = electron1 + electron2;
  combined_e.print_data();

  // 3. Dot product of muons
  std::cout << "\n=== Calculating muon dot product ===\n";
  double muon_dot = muon1.dot_product(muon2);
  std::cout << "Result: " << muon_dot << "\n";

  // 4. Copy assignment (electron)
  std::cout << "\n=== Testing copy assignment operator ===\n";
  Particle electron3("electron", 0, 0, 0, 0);
  std::cout << "Before assignment:\n";
  electron3.print_data();
  electron3 = electron1;
  std::cout << "After assignment:\n";
  electron3.print_data();

  // 5. Copy constructor (muon)
  std::cout << "\n=== Testing copy constructor ===\n";
  Particle muon_copy(muon1);
  muon_copy.print_data();

  // 6. Move assignment (tau)
  std::cout << "\n=== Testing move assignment operator ===\n";
  Particle tau3("tau", 0, 0, 0, 0);
  std::cout << "Before move assignment:\n";
  tau3.print_data();
  tau3 = std::move(tau1);
  std::cout << "After move assignment:\n";
  tau3.print_data();

  // 7. Vector operations with move semantics
  std::cout << "\n=== Testing vector operations ===\n";
  std::vector<Particle> particles;
  particles.reserve(3);
    
  std::cout << "Adding temporary particle to vector:\n";
  particles.push_back(Particle("tau", 1777, 5.1, 5.2, 5.3));
    
  std::cout << "\nMoving tau2 into vector:\n";
  particles.push_back(std::move(tau2));

  // 8. Memory verification
  std::cout << "\n=== Memory Address Verification ===\n";
  std::cout << "Original tau2 (moved-from):\n";
  tau2.print_data();
  std::cout << "Vector particle (moved-to):\n";
  particles[1].print_data();

  return 0;
}