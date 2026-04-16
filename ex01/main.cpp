/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:00 by yoshin            #+#    #+#             */
/*   Updated: 2026/03/26 18:00:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
  Data data;
  Data *result;
  uintptr_t raw;

  data.name = "test_data";
  data.value = 42;

  std::cout << "=== Original Data ===" << std::endl;
  std::cout << "Address: " << &data << std::endl;
  std::cout << "Name:    " << data.name << std::endl;
  std::cout << "Value:   " << data.value << std::endl;

  raw = Serializer::serialize(&data);
  std::cout << std::endl;
  std::cout << "=== Serialized ===" << std::endl;
  std::cout << "Raw:     " << raw << std::endl;

  result = Serializer::deserialize(raw);
  std::cout << std::endl;
  std::cout << "=== Deserialized ===" << std::endl;
  std::cout << "Address: " << result << std::endl;
  std::cout << "Name:    " << result->name << std::endl;
  std::cout << "Value:   " << result->value << std::endl;

  std::cout << std::endl;
  std::cout << "=== Verification ===" << std::endl;
  if (result == &data)
    std::cout << "SUCCESS: Pointers match!" << std::endl;
  else
    std::cout << "FAILURE: Pointers do not match!" << std::endl;

  if (result->name == "test_data" && result->value == 42)
    std::cout << "SUCCESS: Data is intact!" << std::endl;
  else
    std::cout << "FAILURE: Data is corrupted!" << std::endl;

  return (0);
}
