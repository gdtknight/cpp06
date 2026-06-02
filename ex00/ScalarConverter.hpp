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
  static bool fitsInInt(double value);
  static bool isWhole(double value);

  static void convertPseudo(std::string const &literal);
  static void convertAll(double value);

  static void printChar(double value);
  static void printInt(double value);
  static void printFloat(double value);
  static void printDouble(double value);

public:
  static void convert(std::string const &literal);
};

#endif
