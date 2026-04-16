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
  std::string::size_type i = 0;
  bool hasDot = false;

  if (literal.empty())
    return (false);
  if (literal[literal.length() - 1] != 'f')
    return (false);
  if (literal[i] == '+' || literal[i] == '-')
    i++;
  if (i >= literal.length() - 1)
    return (false);
  while (i < literal.length() - 1)
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

void ScalarConverter::printChar(double value, bool isPseudo)
{
  std::cout << "char: ";
  if (isPseudo || value != value
    || value < 0 || value > 127)
    std::cout << "impossible" << std::endl;
  else if (!std::isprint(static_cast<int>(value)))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool isPseudo)
{
  std::cout << "int: ";
  if (isPseudo || value != value
    || value < static_cast<double>(std::numeric_limits<int>::min())
    || value > static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool isPseudo)
{
  float f;

  std::cout << "float: ";
  if (isPseudo || value != value)
  {
    f = static_cast<float>(value);
    if (f != f)
      std::cout << "nanf" << std::endl;
    else if (f > 0)
      std::cout << "+inff" << std::endl;
    else
      std::cout << "-inff" << std::endl;
    return ;
  }
  f = static_cast<float>(value);
  if (f == static_cast<int>(f)
    && f >= static_cast<float>(std::numeric_limits<int>::min())
    && f <= static_cast<float>(std::numeric_limits<int>::max()))
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  else
    std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double value, bool isPseudo)
{
  std::cout << "double: ";
  if (isPseudo || value != value)
  {
    if (value != value)
      std::cout << "nan" << std::endl;
    else if (value > 0)
      std::cout << "+inf" << std::endl;
    else
      std::cout << "-inf" << std::endl;
    return ;
  }
  if (value == static_cast<int>(value)
    && value >= static_cast<double>(std::numeric_limits<int>::min())
    && value <= static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
  else
    std::cout << value << std::endl;
}

void ScalarConverter::convertPseudo(std::string const &literal)
{
  double value;

  if (literal == "nan" || literal == "nanf")
    value = std::numeric_limits<double>::quiet_NaN();
  else if (literal == "+inf" || literal == "+inff"
    || literal == "inf" || literal == "inff")
    value = std::numeric_limits<double>::infinity();
  else
    value = -std::numeric_limits<double>::infinity();
  printChar(value, true);
  printInt(value, true);
  printFloat(value, true);
  printDouble(value, true);
}

void ScalarConverter::convertFromChar(char c)
{
  double value;

  value = static_cast<double>(c);
  printChar(value, false);
  printInt(value, false);
  printFloat(value, false);
  printDouble(value, false);
}

void ScalarConverter::convertFromInt(long value)
{
  double dval;

  dval = static_cast<double>(value);
  printChar(dval, false);
  if (value < static_cast<long>(std::numeric_limits<int>::min())
    || value > static_cast<long>(std::numeric_limits<int>::max()))
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(value) << std::endl;
  printFloat(dval, false);
  printDouble(dval, false);
}

void ScalarConverter::convertFromFloat(float value)
{
  double dval;

  dval = static_cast<double>(value);
  printChar(dval, false);
  printInt(dval, false);
  printFloat(dval, false);
  printDouble(dval, false);
}

void ScalarConverter::convertFromDouble(double value)
{
  printChar(value, false);
  printInt(value, false);
  printFloat(value, false);
  printDouble(value, false);
}

void ScalarConverter::convert(std::string const &literal)
{
  if (literal.empty())
  {
    std::cout << "Error: empty literal" << std::endl;
    return ;
  }
  if (isPseudoLiteral(literal))
  {
    convertPseudo(literal);
    return ;
  }
  if (isCharLiteral(literal))
  {
    convertFromChar(literal[0]);
    return ;
  }
  if (isIntLiteral(literal))
  {
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    convertFromInt(val);
    return ;
  }
  if (isFloatLiteral(literal))
  {
    float val = std::strtof(literal.c_str(), NULL);
    convertFromFloat(val);
    return ;
  }
  if (isDoubleLiteral(literal))
  {
    double val = std::strtod(literal.c_str(), NULL);
    convertFromDouble(val);
    return ;
  }
  std::cout << "Error: invalid literal" << std::endl;
}
