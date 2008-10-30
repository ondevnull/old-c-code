/* 
 * File: main.cc
 * Author: Jose Luis Rivas <ghostbar38@gmail.com>
 * Created on July 16, 2008, 11:46
 *
 * Copyright (c) 2008 Jose Luis Rivas <ghostbar38@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <iostream>
#include <string>
#include <gtkmm.h>
#include <libglademm.h>

/*
 * Name: main
 * Description:
 * Args:
 * Input:
 * Output:
 */
int main(int argc, char** argv) {
	/* Creating the Gtk::Main kit */
	Gtk::Main kit(argc, argv);
	/* Calling the Glade file and checking for errors */
	Glib::RefPtr<Gnome::Glade::Xml> refXml;
	#ifdef GLIBMM_EXCEPTIONS_ENABLED
		try {
			refXml = Gnome::Glade::Xml::create("checkers44-gtk.glade");
		} catch (const Gnome::Glade::XmlError& ex) {
			std::cerr << ex.what() << std::endl;
			return (1);
		}
	#else
		std::auto_ptr<Gnome:Glade::XmlError> error;
		refXml = Gnome::Glade::Xml::create("checkers44-gtk.glade", "", "", error);
		if (error.get()) {
			std::cerr << error->what() << std::endl;
			return (1);
		}
	#endif

	/* Getting the Main Window */
	Gtk::Window* pMain = 0;
	refXml->get_widget("main", pMain);
	if (pMain) {
		std::cout << "Entro!" << std::endl;
		/* Showing the main window */
		kit.run(*pMain);
	}
	return (0);
}


