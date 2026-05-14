/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:53:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/05/14 17:21:15 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base(void) {}

Base *generate(void) {
  int roll = std::rand() % 3;

  if (roll == 0)
    return (new A());
  if (roll == 1)
    return (new B());
  return (new C());
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
    return;
  }
  if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
    return;
  }
  if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
    return;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception const &) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception const &) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception const &) {
  }
}
