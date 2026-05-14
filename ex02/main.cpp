/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:53:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/05/14 15:53:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
  std::srand(std::time(NULL));

  for (int i = 0; i < 10; i++) {
    Base *base = generate();
    std::cout << "identify(Base*): ";
    identify(base);
    std::cout << "identify(Base&): ";
    identify(*base);
    delete base;
  }
  return (0);
}
