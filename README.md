# Infinite Jetpac Lives

Gives the player infinite lives in the Jetpac mini-game in DK64 Recompiled.

Jetpac is playable in Cranky's Lab and is required to earn the Rareware Coin.

## Installation

1. Download the latest `infinite_jetpac_lives.nrm` from [Releases](../../releases/latest).
2. Place it in your DK64 Recompiled mods folder:
   - **Windows:** `%LOCALAPPDATA%\DK64Recompiled\mods`
   - **Linux:** `~/.local/share/DK64Recompiled/mods`
3. Launch DK64 Recompiled and enable the mod from the mods menu.

## Building from Source

### Requirements

- `clang` with MIPS target support (LLVM, not Apple clang)
- `ld.lld`
- `make`

> **macOS:** Apple clang does not support MIPS. Install LLVM via `brew install llvm` and pass
> `CC=/opt/homebrew/opt/llvm/bin/clang LD=/opt/homebrew/opt/llvm/bin/ld.lld` to make.

### Steps

```bash
git clone --recurse-submodules git@github.com:cdalong/JetPacInfiniteLives.git
cd JetPacInfiniteLives
make
./build.sh
```

The mod file is written to `bin/infinite_jetpac_lives.nrm`.

You can also output directly to your mods folder instead of using `build.sh`:

```bash
./RecompModTool mod.toml ~/.local/share/DK64Recompiled/mods
```

## How It Works

Patches `func_jetpac_80026A3C`, the player death handler in the Jetpac overlay.
The original function waits 14 frames after death then decrements `player->lives` before
triggering the respawn sequence. The patch skips the decrement — lives never reach -1
so the game-over check never fires.

## Project Layout

| Path | Description |
|---|---|
| `src/main.c` | Patch implementation |
| `include/jetpac_int.h` | Minimal Jetpac struct definitions |
| `mod.toml` | Mod metadata and packaging config |
| `Dk64Syms/` | DK64 symbol tables used by RecompModTool |
| `dk64_decomp/` | DK64 decomp headers used during compilation |
