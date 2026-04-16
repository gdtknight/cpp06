/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>

class ScalarConverter
{
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &src);
  ScalarConverter &operator=(ScalarConverter const &rhs);
  ~ScalarConverter(void);

  static bool isCharLiteral(std::string const &literal);
  static bool isIntLiteral(std::string const &literal);
  static bool isFloatLiteral(std::string const &literal);
  static bool isDoubleLiteral(std::string const &literal);
  static bool isPseudoLiteral(std::string const &literal);

  static void convertFromChar(char c);
  static void convertFromInt(long value);
  static void convertFromFloat(float value);
  static void convertFromDouble(double value);
  static void convertPseudo(std::string const &literal);

  static void printChar(double value, bool isPseudo);
  static void printInt(double value, bool isPseudo);
  static void printFloat(double value, bool isPseudo);
  static void printDouble(double value, bool isPseudo);

public:
  static void convert(std::string const &literal);
};

#endif
