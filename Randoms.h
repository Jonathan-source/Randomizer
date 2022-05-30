/*
	This header file provides helpful and convenient functionality for a variety of randomness use cases.
	This isn't a fully optimized library; rather, it's a collection of copy-paste stuff that can be utilized in other projects.
	
	Updated: 2022-05-25
	Author: Jonathan Helsing
*/

#pragma once

#ifndef __cplusplus
	#error Randomizer.h requires C++
#endif

#include <random>
#include <numeric>
#include <chrono>
#include <cassert>
#include <fstream>
#include <string>

namespace Random {

	uint32_t Uint32(uint32_t lower_value = 0u, uint32_t upper_value = 100u) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		if (lower_value <= upper_value) {
			static std::uniform_int_distribution<std::mt19937::result_type> uni(lower_value, upper_value);
			return uni(engine);
		} else {
			static std::uniform_int_distribution<std::mt19937::result_type> uni(upper_value, lower_value);
			return uni(engine);
		}
	}

	int32_t Int32(int32_t lower_value = -100, int32_t upper_value = 100) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		if (lower_value <= upper_value) {
			static std::uniform_int_distribution<int32_t> uni(lower_value, upper_value);
			return uni(engine);
		} else {
			static std::uniform_int_distribution<int32_t> uni(upper_value, lower_value);
			return uni(engine);
		}
	}

	float Float(float low = 0.f, float high = 1.f) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		if (low <= high) {
			static std::uniform_real_distribution<float> unif(low, high);
			return unif(engine);
		} else {
			static std::uniform_real_distribution<float> unif(high, low);
			return unif(engine);
		}
	}

	double Double(double low = 0.0, double high = 1.0) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		if (low <= high) {
			static std::uniform_real_distribution<double> unif(low, high);
			return unif(engine);
		} else {
			static std::uniform_real_distribution<double> unif(high, low);
			return unif(engine);
		}
	}

	bool Bool() {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		static std::uniform_int_distribution<std::mt19937::result_type> uni(0, 1);
		return uni(engine);
	}

	char Char() {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		static std::uniform_int_distribution<std::mt19937::result_type> uni(0, 255);
		return uni(engine);
	}

	enum class ETypo{ lowercase, uppercase, randomcase };
	char Letter(ETypo typography = ETypo::lowercase) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };
		static std::uniform_int_distribution<std::mt19937::result_type> uni(97, 122);
		static std::uniform_int_distribution<std::mt19937::result_type> typo(0, 1);
		if (typography == ETypo::randomcase) typography = static_cast<ETypo>(typo(engine));
		return (typography == ETypo::lowercase) ? uni(engine) : std::toupper(uni(engine));
	}

	enum class EGender{ male, female, random };
	//! [Not optimized] Provides a random name from a pool of 18´239 unique names.
	std::string Name(EGender gender = EGender::random) {
		static uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		static std::seed_seq ss{ uint32_t(seed & 0xffffffff), uint32_t(seed >> 32) };
		static std::mt19937 engine{ ss };	
		std::fstream reader;
		std::string name{ "Random::Name() failed due to unknown error. Make sure 'names.txt' exist." };
		reader.open("names.txt");
		if (reader.is_open()) {
			const size_t nrOfNames = std::count(std::istreambuf_iterator<char>(reader),
				std::istreambuf_iterator<char>(), '\n');
			static std::uniform_int_distribution<std::mt19937::result_type> uni(0, static_cast<uint32_t>(nrOfNames));
			reader.seekg(0, std::ios::beg);
			uint32_t start = 0, dest = uni(engine);
			while (!reader.eof() && start != dest) {
				reader >> name;
				start++;
			}
			reader.close();
		} else {
			reader.clear();
		}
		return name;
	}

} // end of namespace.