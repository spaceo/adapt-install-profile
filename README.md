*********************
ADAPT INSTALL PROFILE
*********************

/*
 * File / Folder structure
 */

adapt_install_profile.info: Definition of all needed modules (core, contrib & custom) that are needed
for a basic setup. Everything defined here will be installed no matter what and is not optional.

adapt_install_profile.make: Make file

distro.make: Distro file

adapt_install_profile.install: Where most of the magic happens. Will include all the files in the /includes folder.

adapt_install_profile.profile: Holds the config for the Base Settings form.

/includes: Include files. Basically outsourcing of logic from the .install file to keep a nice overview of
things. All logic in these files will be executed and is not optional. All optional stuff will be packed into
seperate modules and will be available on the Basic Settings form.

/modules: All modules that are not downloaded through the build script, e.a. custom Adapt modules.
