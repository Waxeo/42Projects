#include "Serializer.hpp"

int	main()
{
	Data data;
	uintptr_t stock = 0;

	data.test = 42;
	std::cout << "data = " << data.test << std::endl;

	stock = Serializer::serialize(&data);

	std::cout << stock << std::endl;

	Data *data2 = Serializer::deserialize(stock);

	std::cout << "data2 = " << data2->test << std::endl;

}