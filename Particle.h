/*
Purpose: Declares the Particle class interface.
Student ID: 10821713
Date: 07/03/2025
Description: Header file for Particle class containing member variable declarations, 
             validation functions, and prototypes for constructors, operators, 
             and utility functions. Manages particle name and four-momentum data.
*/

#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <string>

class Particle 
{
private:
  std::string name;
  std::vector<double>* four_momentum;  // Dynamically allocated

  // Private validation functions
  bool is_valid_name(const std::string& particle_name) const;
  bool is_valid_energy(double energy) const;

public:
  // Constructor & Destructor
  Particle(const std::string& name, double E, double px, double py, double pz);
  ~Particle();

  // Copy semantics
  Particle(const Particle& other);
  Particle& operator=(const Particle& other);

  // Move semantics (Challenge)
  Particle(Particle&& other) noexcept;
  Particle& operator=(Particle&& other) noexcept;

  // Getters
  std::string get_name() const;
  double get_E() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;

  // Setters with validation
  void set_name(const std::string& new_name);
  void set_E(double new_E);
  void set_px(double new_px);
  void set_py(double new_py);
  void set_pz(double new_pz);

  // Operator overloads
  Particle operator+(const Particle& other) const;
  double dot_product(const Particle& other) const;

  // Utility function
  void print_data() const;
};

#endif
