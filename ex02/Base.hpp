/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:02:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/05/13 10:02:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
  virtual ~Base(void);
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
