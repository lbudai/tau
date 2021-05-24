#include <Muon/Muon.h>
#include "m6502.h"

class M6502StatusFlagChangeTests : public testing::Test
{
public:
	m6502::Mem mem;
	m6502::CPU cpu;

	virtual void SetUp()
	{
		cpu.Reset( mem );
	}

	virtual void TearDown()
	{
	}
};

TEST_F( M6502StatusFlagChangeTests, CLCWillClearTheCarryFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.C = true;
	mem[0xFF00] = CPU::INS_CLC;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_FALSE( cpu.Flag.C );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.I, CPUCopy.Flag.I );
	CHECK_EQ( cpu.Flag.D, CPUCopy.Flag.D );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, SECWillSetTheCarryFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.C = false;
	mem[0xFF00] = CPU::INS_SEC;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_TRUE( cpu.Flag.C );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.I, CPUCopy.Flag.I );
	CHECK_EQ( cpu.Flag.D, CPUCopy.Flag.D );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, CLDWillClearTheDecimalFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.D = true;
	mem[0xFF00] = CPU::INS_CLD;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_FALSE( cpu.Flag.D );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.I, CPUCopy.Flag.I );
	CHECK_EQ( cpu.Flag.C, CPUCopy.Flag.C );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, SEDWillSetTheDecimalFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.D = false;
	mem[0xFF00] = CPU::INS_SED;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_TRUE( cpu.Flag.D );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.I, CPUCopy.Flag.I );
	CHECK_EQ( cpu.Flag.C, CPUCopy.Flag.C );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, CLIWillClearTheInterruptFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.I = true;
	mem[0xFF00] = CPU::INS_CLI;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_FALSE( cpu.Flag.I );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.D, CPUCopy.Flag.D );
	CHECK_EQ( cpu.Flag.C, CPUCopy.Flag.C );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, SEIWillSetTheInterruptFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.I = false;
	mem[0xFF00] = CPU::INS_SEI;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_TRUE( cpu.Flag.I );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.D, CPUCopy.Flag.D );
	CHECK_EQ( cpu.Flag.C, CPUCopy.Flag.C );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.V, CPUCopy.Flag.V );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

TEST_F( M6502StatusFlagChangeTests, CLVWillClearTheOverflowFlag )
{
	// given:
	using namespace m6502;
	cpu.Reset( 0xFF00, mem );
	cpu.Flag.V = true;
	mem[0xFF00] = CPU::INS_CLV;
	constexpr s32 EXPECTED_CYCLES = 2;
	CPU CPUCopy = cpu;

	// when:
	const s32 ActualCycles = cpu.Execute( EXPECTED_CYCLES, mem );

	// then:
	CHECK_EQ( ActualCycles, EXPECTED_CYCLES );
	CHECK_FALSE( cpu.Flag.V );
	CHECK_EQ( cpu.Flag.Z, CPUCopy.Flag.Z );
	CHECK_EQ( cpu.Flag.D, CPUCopy.Flag.D );
	CHECK_EQ( cpu.Flag.C, CPUCopy.Flag.C );
	CHECK_EQ( cpu.Flag.B, CPUCopy.Flag.B );
	CHECK_EQ( cpu.Flag.I, CPUCopy.Flag.I );
	CHECK_EQ( cpu.Flag.N, CPUCopy.Flag.N );
}

