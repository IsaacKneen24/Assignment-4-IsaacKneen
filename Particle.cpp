/*
Purpose: Defines the Particle class member functions.
Student ID: 10821713
Date: 07/03/2025
Description: Implements particle physics operations including constructors/destructors, 
             move/copy semantics, operator overloads (+ and dot product), and memory 
             management for dynamically allocated four-momentum vectors. Includes 
             validation for particle names and energy values.
*/

#include "Particle.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Valid particle names (expanded list)
const std::vector<std::string> valid_names = {
  "electron", "muon", "tau", "combined_particle"
};

// Constructor
Particle::Particle(const std::string& name, double E, double px, double py, double pz) 
  : name(name), four_momentum(new std::vector<double>{E, px, py, pz}) 
{
  if(!is_valid_name(name)) 
  {
    throw std::invalid_argument("Invalid particle name");
  }
  if(!is_valid_energy(E)) 
  {
    throw std::invalid_argument("Energy cannot be negative");
  }
  std::cout << "Calling Constructor\n";
}

// Destructor
Particle::~Particle() 
{
  delete four_momentum;
  std::cout << "Calling Destructor\n";
}

// Copy Constructor
Particle::Particle(const Particle& other) 
  : name(other.name), four_momentum(new std::vector<double>(*other.four_momentum)) 
{
  std::cout << "Calling Copy Constructor\n";
}

// Copy Assignment Operator
Particle& Particle::operator=(const Particle& other) 
{
  if(this != &other) 
  {
    name = other.name;
    *four_momentum = *other.four_momentum;
  }
  std::cout << "Calling Copy Assignment\n";
  return *this;
}

// Move Constructor
Particle::Particle(Particle&& other) noexcept 
  : name(std::move(other.name)), four_momentum(other.four_momentum) 
{
  other.four_momentum = nullptr;
  std::cout << "Calling Move Constructor\n";
}

// Move Assignment Operator
Particle& Particle::operator=(Particle&& other) noexcept 
{
  if(this != &other) 
  {
    delete four_momentum;
    name = std::move(other.name);
    four_momentum = other.four_momentum;
    other.four_momentum = nullptr;
    std::cout << "Calling Move Assignment\n";
  }
  return *this;
}

// Getters
std::string Particle::get_name() const { return name; }
double Particle::get_E() const { return (*four_momentum)[0]; }
double Particle::get_px() const { return (*four_momentum)[1]; }
double Particle::get_py() const { return (*four_momentum)[2]; }
double Particle::get_pz() const { return (*four_momentum)[3]; }

// Setters
void Particle::set_name(const std::string& new_name) 
{
  if(!is_valid_name(new_name)) 
  {
    throw std::invalid_argument("Invalid particle name");
  }
  name = new_name;
}

void Particle::set_E(double new_E) 
{
    if(!is_valid_energy(new_E)) 
    {
      throw std::invalid_argument("Energy cannot be negative");
    }
    (*four_momentum)[0] = new_E;
}

void Particle::set_px(double new_px) { (*four_momentum)[1] = new_px; }
void Particle::set_py(double new_py) { (*four_momentum)[2] = new_py; }
void Particle::set_pz(double new_pz) { (*four_momentum)[3] = new_pz; }

// Operator Overloads
Particle Particle::operator+(const Particle& other) const 
{
  return Particle(
    "combined_particle",
    this->get_E() + other.get_E(),
    this->get_px() + other.get_px(),
    this->get_py() + other.get_py(),
    this->get_pz() + other.get_pz()
    );
}

double Particle::dot_product(const Particle& other) const 
{
  return (this->get_E() * other.get_E()) 
        - (this->get_px() * other.get_px())
        - (this->get_py() * other.get_py())
        - (this->get_pz() * other.get_pz());
}

// Validation Functions
bool Particle::is_valid_name(const std::string& particle_name) const 
{
  return std::find(valid_names.begin(), valid_names.end(), particle_name) 
    != valid_names.end();
}

bool Particle::is_valid_energy(double energy) const 
{
  return energy >= 0;
}

// Print Function
void Particle::print_data() const 
{
  std::cout << "Particle: " << name << "\n"
            << "Memory address: " << this << "\n";
  
  if (four_momentum)  // Check if pointer is valid
  {
    std::cout << "Four-momentum: (" 
              << get_E() << ", " 
              << get_px() << ", "
              << get_py() << ", "
              << get_pz() << ")\n";
  }
  else 
  {
    std::cout << "[Moved-from object: No four-momentum]\n";
  }
}
