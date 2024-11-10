Import("env")
env.AddPostAction(
    "$BUILD_DIR/${PROGNAME}.elf",
    env.VerboseAction("pio run -t compiledb", "Generating compile_commands.json")
)
