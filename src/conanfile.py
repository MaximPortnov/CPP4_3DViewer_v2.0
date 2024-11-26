import os
import shutil

from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import cmake_layout
from conan.tools.files import copy, save
from conan.tools.env import VirtualRunEnv, Environment
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def configure(self):
        self.options["qt"].shared = True
        self.options["qt"].mainwindow = True

        
    def requirements(self):
        self.requires("ncurses/6.4")
        self.requires("sqlite3/3.46.1")
        self.requires("qt/6.6.3")

    def layout(self):
        cmake_layout(self)

    
    def generate(self):
        path = self.dependencies["qt"].package_folder.replace("\\", "/")
        save(self, "qt.conf", f"[Paths]\nPrefix = {path}")
        VirtualRunEnv(self).generate()
        if can_run(self):
            VirtualRunEnv(self).generate(scope="build")
        env = Environment()
        env.define("TERM", "dumb")
        env.vars(self, scope="run").save_script("conanrun_term")
        for require, dependency in self.dependencies.items():
            for includedir in dependency.cpp_info.includedirs:
                
                copy(self, "*", includedir, os.path.join(self.source_folder, "include"))
                
            if self.settings.os == "Windows":
               copy(self, "ncursesw/ncurses.h", dependency.cpp_info.includedirs[0], os.path.join(self.source_folder, "include"))
               
    def test(self):
        if can_run(self):
            bin_path = os.path.join(self.cpp.build.bindir, "test_package")
            self.run(bin_path, env="conanrun")
            
            copy(self, "qt.conf", src=self.generators_folder, dst=os.path.join(self.cpp.build.bindirs[0]))
            bin_path = os.path.join(self.cpp.build.bindirs[0], "test_package")
            self.run(bin_path, env="conanrun")
            # Related to https://github.com/conan-io/conan-center-index/issues/20574
            if self.settings.os == "Macos":
                bin_macos_path = os.path.join(self.cpp.build.bindirs[0], "test_macos_bundle.app", "Contents", "MacOS", "test_macos_bundle")
                self.run(bin_macos_path, env="conanrun")