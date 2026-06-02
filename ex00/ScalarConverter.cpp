/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
  (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
  (void)rhs;
  return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

bool ScalarConverter::isCharLiteral(std::string const &literal)
{
  if (literal.length() == 1 && !std::isdigit(literal[0]))
    return (true);
  return (false);
}

bool ScalarConverter::isIntLiteral(std::string const &literal)
{
  std::string::size_type i = 0;

  if (literal.empty())
    return (false);
  if (literal[i] == '+' || literal[i] == '-')
    i++;
  if (i == literal.length())
    return (false);
  while (i < literal.length())
  {
    if (!std::isdigit(literal[i]))
      return (false);
    i++;
  }
  return (true);
}

bool ScalarConverter::isFloatLiteral(std::string const &literal)
{
  if (literal.empty() || literal[literal.length() - 1] != 'f')
    return (false);
  return (isDoubleLiteral(literal.substr(0, literal.length() - 1)));
}

bool ScalarConverter::isDoubleLiteral(std::string const &literal)
{
  std::string::size_type i = 0;
  bool hasDot = false;

  if (literal.empty())
    return (false);
  if (literal[i] == '+' || literal[i] == '-')
    i++;
  if (i >= literal.length())
    return (false);
  while (i < literal.length())
  {
    if (literal[i] == '.')
    {
      if (hasDot)
        return (false);
      hasDot = true;
    }
    else if (!std::isdigit(literal[i]))
      return (false);
    i++;
  }
  return (hasDot);
}

bool ScalarConverter::isPseudoLiteral(std::string const &literal)
{
  return (literal == "nan" || literal == "nanf"
    || literal == "+inf" || literal == "+inff"
    || literal == "-inf" || literal == "-inff"
    || literal == "inf" || literal == "inff");
}

bool ScalarConverter::fitsInInt(double value)
{
  return (value >= static_cast<double>(std::numeric_limits<int>::min())
    && value <= static_cast<double>(std::numeric_limits<int>::max()));
}

bool ScalarConverter::isWhole(double value)
{
  return (fitsInInt(value)
    && value == static_cast<double>(static_cast<int>(value)));
}

void ScalarConverter::printChar(double value)
{
  std::cout << "char: ";
  if (value != value || value < 0 || value > 127)
    std::cout << "impossible" << std::endl;
  else if (!std::isprint(static_cast<int>(value)))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
  std::cout << "int: ";
  if (value != value || !fitsInInt(value))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
  float f;

  std::cout << "float: ";
  f = static_cast<float>(value);
  if (f != f)
    std::cout << "nanf" << std::endl;
  else if (f == std::numeric_limits<float>::infinity())
    std::cout << "+inff" << std::endl;
  else if (f == -std::numeric_limits<float>::infinity())
    std::cout << "-inff" << std::endl;
  else if (isWhole(static_cast<double>(f)))
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  else
  {
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6) << f << "f" << std::endl;
  }
}

void ScalarConverter::printDouble(double value)
{
  std::cout << "double: ";
  if (value != value)
    std::cout << "nan" << std::endl;
  else if (value == std::numeric_limits<double>::infinity())
    std::cout << "+inf" << std::endl;
  else if (value == -std::numeric_limits<double>::infinity())
    std::cout << "-inf" << std::endl;
  else if (isWhole(value))
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
  else
  {
    std::cout.unsetf(std::ios::floatfield);
    std::cout << std::setprecision(6) << value << std::endl;
  }
}

void ScalarConverter::convertAll(double value)
{
  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}

void ScalarConverter::convertPseudo(std::string const &literal)
{
  double value;

  if (literal == "nan" || literal == "nanf")
    value = std::numeric_limits<double>::quiet_NaN();
  else if (literal == "-inf" || literal == "-inff")
    value = -std::numeric_limits<double>::infinity();
  else
    value = std::numeric_limits<double>::infinity();
  convertAll(value);
}

void ScalarConverter::convert(std::string const &literal)
{
  if (literal.empty())
  {
    std::cout << "Error: empty literal" << std::endl;
    return ;
  }
  if (isPseudoLiteral(literal))
    convertPseudo(literal);
  else if (isCharLiteral(literal))
    convertAll(static_cast<double>(literal[0]));
  else if (isIntLiteral(literal))
    convertAll(static_cast<double>(std::strtol(literal.c_str(), NULL, 10)));
  else if (isFloatLiteral(literal))
    convertAll(static_cast<double>(std::strtof(literal.c_str(), NULL)));
  else if (isDoubleLiteral(literal))
    convertAll(std::strtod(literal.c_str(), NULL));
  else
    std::cout << "Error: invalid literal" << std::endl;
}
