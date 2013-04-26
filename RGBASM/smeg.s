;********************************************************************
;																	*
; NAME:	HARDWARE.I													*
; AUTH: JLloyd -- 99/04/12											*
; NOTES: Based on JeffF's hardware defines.							*
;																	*
;																	*
;********************************************************************


; add these registers when you have time
;TIMA_REG	(*(UBYTE *)0xFF05)	/* Timer counter */
;TMA_REG		(*(UBYTE *)0xFF06)	/* Timer modulo */
;TAC_REG		(*(UBYTE *)0xFF07)	/* Timer control */
;RP_REG		(*(UBYTE *)0xFF56)	/* IR port */


r_MBC5_ROM_SEL		EQU		2000h									; rom bank select (write here with bank # (0-63 on GBC with 8Mbit cart))
r_MBC5_ROM_SEL_MSB	EQU		3000h

r_MBC5_WRAM_SEL		EQU		4000h									; ram bank select (write here with bank # (0-7 on GBC))

k_GB_REGS			EQU		FF00h

; VRAM
; GameBoy Video RAM extends from $8000 to $A000, a total of 8KB
k_VRAM				EQU		8000h
k_VRAM_LENGTH		EQU		2000h
k_VRAM_START		EQU		k_VRAM
k_VRAM_END			EQU		((k_VRAM+k_VRAM_LENGTH)-1)

k_VRAM_BG_LOW		EQU		9800h
k_VRAM_BG_HIGH		EQU		9C00h
k_VRAM_TILE_BANK_0	EQU		8000h
k_VRAM_TILE_BANK_1	EQU		8800h
k_VRAM_TILE_BANK_2	EQU		9000h

; HIRAM
; Gameboy HIRAM extends from $FF80 to $FFFF, a total of 128 bytes
k_HIRAM				EQU		FF80h
k_HIRAM_LENGTH		EQU		7Fh
k_HIRAM_START		EQU		k_HIRAM
k_HIRAM_END			EQU		((k_HIRAM+k_HIRAM_LENGTH)-1)

; WRAM
; GameBoy Work RAM extends from $C000 to $E000, a total of 8KB on
; GB and 32KB bank-switched on GBC with 8KB visible at any one time.
k_RAM				EQU		C000h									; $C000->$E000
k_RAM_LENGTH		EQU		2000h
k_RAM_START			EQU		k_RAM
k_RAM_END			EQU		((k_RAM+k_RAM_LENGTH)-1)

k_RAM_BANK_UPR		EQU		D000h
k_RAM_BANK_LENGTH	EQU		1000h
k_RAM_BANK_UPR_START	EQU	k_RAM_BANK_UPR
k_RAM_BANK_UPR_END	EQU		((k_RAM_BANK_UPR+k_RAM_BANK_LENGTH)-1)


; OAM
; GameBoy Object Attribute Map RAM extends from $FE00 to $FE9F. A
; total of 160 bytes.
k_OAMRAM			EQU		FE00h
k_OAMRAM_LENGTH		EQU		A0h
k_OAMRAM_START		EQU		k_OAMRAM
k_OAMRAM_END		EQU		((k_OAMRAM+k_OAMRAM_LENGTH)-1)

_AUD3WAVERAM		EQU		FF30h									; $FF30->$FF3F		; not sure!


k_COLOUR_GREY			EQU		3
k_COLOUR_DARK_GREY		EQU		2
k_COLOUR_LIGHT_GREY		EQU		1
k_COLOUR_TRANSPARENT	EQU		0





		SECTION	"Home",DATA

TEST	EQU		0
TEST2	EQU		Fh
TEST3	EQU		10h
TEST4	EQU		3000h
pic1:
		DW		01230123g

		SECTION	"Home2",CODE
;		LD		A,$11
		LD		A,1h
		LD		A,(HL)
		LD		A,FFh
		LD		A,0Fh
		LD		BC,0FFFh
		LD		BC,EFFEh
		LD		BC,9FFh
		LD		BC,FF9h

		LD		A,1o
		LD		A,77o
		LD		A,07o
		LD		BC,0777o
		LD		BC,6767o
		LD		BC,477o
		LD		BC,774o

		DQ		1
;		ALIGN	[16]
		RET