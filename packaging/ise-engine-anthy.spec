#sbs-git:slp/pkgs/e/edje edje 1.1.0+svn.69011slp2+build03 96cd9783918ce594c786d12a5107be27aec4d34b
Name:       ise-engine-anthy
Summary:    Japanese input method
Version:    0.0.0125
Release:    1
Group:      TO_BE/FILLED_IN
License:    BSD
URL:        http://www.enlightenment.org/
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  prelink
BuildRequires:  gettext-tools
BuildRequires:  pkgconfig(isf)
BuildRequires:  pkgconfig(anthy)


%description
ISF is an input service framework for TIZEN.
Ise-engine-anthy is ISF IMEngine module for Japanese input method base.It converts Hiragana text to Kana Kanji mixed text.



%prep
%setup -q

%build
./bootstrap
%configure --prefix=%{_prefix} --disable-static

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install


%files
%defattr(-,root,root,-)
%{_datadir}/scim/icons/*
%{_datadir}/locale/*
%{_datadir}/scim/Anthy/*
%{_libdir}/scim-1.0/1.4.0/IMEngine/*
